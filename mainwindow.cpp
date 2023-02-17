/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "work.h"
#include "powersupply.h"

#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>

#include <QDebug>



extern ulong userTimer;
extern uint8_t MasterOnFlag1;
extern uint8_t MasterOnFlag2;

//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//! [0]
    ui->setupUi(this);
    console = new Console;
    console->setEnabled(false);
    setCentralWidget(console);
//! [1]
    serial = new QSerialPort(this);
//! [1]
    settings = new SettingsDialog;

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);



    userwork = new work;
    userPowerSupply = new PowerSupply;


    initActionsConnections();


    connect(serial,             SIGNAL(error(QSerialPort::SerialPortError)),    this,               SLOT(handleError(QSerialPort::SerialPortError)));
    connect(serial,             SIGNAL(readyRead()),                            this,               SLOT(readData()));
    connect(console,            SIGNAL(getData(QByteArray)),                    this,               SLOT(writeData(QByteArray)));
    connect(console,            SIGNAL(sendSerialPortData(QByteArray, ulong)),  userwork,           SLOT(getSerialPortData(QByteArray, ulong)));//user code for echo
    connect(this,               SIGNAL(userInformPortStatus(uint)),             userwork,           SLOT(getInformPortStatus(uint)));//user code for status
    connect(userwork,           SIGNAL(userStopPort()),                         this,               SLOT(closeSerialPort()));//user code for stop serial port
    connect(userwork,           SIGNAL(userSignalSaveDataToFile()),             userwork,           SLOT(userSaveDataToFile()));
    connect(userwork,           SIGNAL(Master1On(uint8_t)),                     userPowerSupply,    SLOT(Master2Comunication(uint8_t)));
    connect(userPowerSupply,    SIGNAL(Master2On(uint8_t)),                     userwork,           SLOT(Master1Comunication(uint8_t)));
    connect(console,            SIGNAL(sendSerialPortData(QByteArray, ulong)),  userPowerSupply,    SLOT(getSerialPortData(QByteArray, ulong)));//user code for echo
    connect(userPowerSupply,    SIGNAL(getData(QByteArray)),                    this,               SLOT(writeData(QByteArray)));


//! [3]
}
//! [3]

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}



//! [4]
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));

    emit userInformPortStatus(1);//user code

    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}
//! [4]




//! [5]
void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));

    userTimer = 0;//user
    emit userInformPortStatus(0);//user code
}
//! [5]




void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}



//! [6] //getData
void MainWindow::writeData(const QByteArray &data)
{


    qDebug() << "Data length to send :" << data.length();

    for(uint8_t i = 0; i < 16; i++)
    {
        qDebug() << "Data to send :" << "Index:"<< i <<"Data:" << data[i];
    }

    serial->write(data, data.length());
}


//! [6]

//! [7]
void MainWindow::readData()
{
    QByteArray data = serial->readAll();


    console->putData(data);
    //здесь выпустим сигнал
    //emit sendSerialPortData(data, data.length());//user code

    //слот подхватит сигнал и будет обрабатывать
    //void PowerSupply::getSerialPortData(const QByteArray &data, ulong userCounter)

    //for user

}
//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//! [8]

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect,      SIGNAL(triggered()), this,              SLOT(openSerialPort()));
    connect(ui->actionDisconnect,   SIGNAL(triggered()), this,              SLOT(closeSerialPort()));
    connect(ui->actionQuit,         SIGNAL(triggered()), this,              SLOT(close()));
    connect(ui->actionConfigure,    SIGNAL(triggered()), settings,          SLOT(show()));
    connect(ui->actionClear,        SIGNAL(triggered()), console,           SLOT(clear()));
    connect(ui->actionAbout,        SIGNAL(triggered()), this,              SLOT(about()));
    connect(ui->actionAboutQt,      SIGNAL(triggered()), qApp,              SLOT(aboutQt()));

    connect(ui->actionUserWork,     SIGNAL(triggered()), userwork ,         SLOT(show()));
    connect(ui->actionPowerSupply,  SIGNAL(triggered()), userPowerSupply,   SLOT(show()));

}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}










