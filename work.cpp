#include "work.h"
#include "ui_work.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

#include "database.h"

#include <QDebug>

ulong userTimer = 0;//user code



work::work(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::work)
{
    ui->setupUi(this);

    ui->lcdN_1->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdN_1->setStyleSheet("background-color: yellow;"
                              "color:green;");
    ui->lcdTimer->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdTimer->setStyleSheet("background-color: yellow;"
                              "color:green;");

    MasterOnFlag1 = 0;
    userFlagPlotRange = 0;
    userflagDataClear = 0;
    userflagStopPort = 0;
    userColumn = 3;

}

work::~work()
{
    delete ui;
}

void work::getSerialPortData(const QByteArray &data, ulong userCounter)
{

    if(MasterOnFlag1 == 1)//MasterOn = On
    {
        QString txt;

        if(userflagStopPort)
        {
            ui->userDataCollect->setStyleSheet("background-color: #f0f0f0;");
            userflagStopPort = 0;
        }

        ui->workOut->setText(data);
        ui->lcdN_1->display(txt.append(data).split(' ')[1]);//
        ui->lcdTimer->display((double)userCounter);

        //
        if(userCounter < NUMBER_POINTS)
        {
            ui->userDataReady->setStyleSheet("background-color: #f0f0f0;");

            //----------Formation of the data----------------------------------------
            x.append(userCounter);
            y.append(txt.append(data).split(' ')[1].toDouble());
            //-----------------------------------------------------------------------

            userRaw = (uint8_t)userCounter;

            userTable[userCounter][1] = x.value(userCounter);
            userTable[userCounter][2] = y.value(userCounter);

            //----------Plot----------------------------------------------------------
            ui->customPlot->addGraph();
            ui->customPlot->xAxis->setLabel("x(timers)");
            ui->customPlot->yAxis->setLabel("y(value)");
            ui->customPlot->graph(0)->setData(x,y);

            if((y[userCounter] < 100) && (userFlagPlotRange < 1))
            {
                ui->customPlot->yAxis->setRange(0, 100);
            } else {
                if((y[userCounter] < 500) && (userFlagPlotRange < 2))
                {
                    ui->customPlot->yAxis->setRange(0, 500);
                    userFlagPlotRange = 1;
                } else {
                    ui->customPlot->yAxis->setRange(0, 10000);
                    userFlagPlotRange = 2;
                }
            }

            if(x[userCounter] < (NUMBER_POINTS/4))
            {
                ui->customPlot->xAxis->setRange(0, NUMBER_POINTS/4);
            } else {
                if(x[userCounter] < (NUMBER_POINTS/2))
                {
                    ui->customPlot->xAxis->setRange(0, NUMBER_POINTS/2);
                } else {
                    ui->customPlot->xAxis->setRange(0, NUMBER_POINTS);
                }
            }

            ui->customPlot->replot();
            //----------Plot--------------------------------------------------------

        } else {
            ui->userDataReady->setStyleSheet("background-color: green;");
            userFlagPlotRange = 0;
        }
        //

    }

}

void work::getInformPortStatus(uint userPortStatus)
{
    if(userPortStatus)
    {
        ui->userPortStatus->setStyleSheet("background-color: green;");
        userflagDataClear = 0;
    } else {
        ui->userPortStatus->setStyleSheet("background-color: #f0f0f0;");
    }
}


void work::on_userDataCollect_pressed()
{
    ui->userDataCollect->setStyleSheet("background-color: green;");
    ui->userDataClear->setStyleSheet("background-color: green;");

    userflagStopPort = 1;
    userflagDataClear = 1;

    userInputTableData();

    emit userSignalSaveDataToFile();
    emit userStopPort();
}

void work::on_userDataClear_pressed()
{
    if(userflagDataClear)
    {
        x.clear();
        y.clear();

        ui->usertableWidget->clear();
        ui->customPlot->clearGraphs();
        ui->customPlot->replot();

        ui->workOut->clear();
        ui->lcdN_1->display((double)0);
        ui->lcdTimer->display((double)0);

        userClearTable();

        ui->userDataClear->setStyleSheet("background-color: #f0f0f0;");
        ui->userDataCollect->setStyleSheet("background-color: #f0f0f0;");
    }
}

void work::userInputTableData()
{
    //Fill in usertableWidget with the data
    ui->usertableWidget->setRowCount(userRaw);
    ui->usertableWidget->setColumnCount(userColumn);
    for(uint i = 0; i < userRaw; i++)
    {
        for(uint j = 0; j < 3; j++)
        {
            ui->usertableWidget->setItem(i, j, new QTableWidgetItem(QString("%1").arg(userTable[i][j])));

        }
    }
}

void work::userClearTable()
{
    for(uint i = 0; i < userRaw; i++)
    {
        for(uint j = 0; j < 3; j++)
        {
            userTable[i][j] = 0;
        }
    }
}

void work::userSaveDataToFile()
{
    QFile fileX("x.txt");
    QFile fileY("y.txt");

    if(fileX.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // Если файл успешно открыт для записи в текстовом режиме
            QTextStream out(&fileX); // Создаем объект класса QTextStream
        // и передаем ему адрес объекта fileX

        for(uint i = 0; i < userRaw; i++)
        {
           out << userTable[i][1]; // Посылаем строку в поток для записи
           out << '\n';

           //out.flush();
        }

        fileX.close(); // Закрываем файл
    }

    if(fileY.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // Если файл успешно открыт для записи в текстовом режиме
            QTextStream out(&fileY); // Создаем объект класса QTextStream
        // и передаем ему адрес объекта fileX

       for(uint i = 0; i < userRaw; i++)
       {
           out << userTable[i][2]; // Посылаем строку в поток для записи
           out << '\n';

           //out.flush();
        }

        fileY.close(); // Закрываем файл
    }
}




void work::Master1Comunication(uint8_t Flag)
{

    if(Flag == 2)
    {
       MasterOnFlag1 = 0;
       ui->buttonMasterOn->setStyleSheet("background-color: #f0f0f0;");
    } else {
        MasterOnFlag1 = 1;
    }
}


void work::on_buttonMasterOn_pressed()
{
    ui->buttonMasterOn->setStyleSheet("background-color: green;");
    emit Master1On(1);
}
