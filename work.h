#ifndef WORK_H
#define WORK_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>

#include "qcustomplot.h"//plot
#include <QVector>//data gathering

#include "database.h"


namespace Ui {
class work;
}

class work : public QWidget
{
    Q_OBJECT

public:
    explicit work(QWidget *parent = 0);
    ~work();

    QVector<double> x, y;
    double userTable[NUMBER_POINTS][3];
    uint8_t userRaw;
    uint8_t userColumn;
    uint8_t userFlagPlotRange;
    uint8_t userflagDataClear;
    uint8_t userflagStopPort;

    uint8_t MasterOnFlag1;

signals:
    void userDataClear();
    void userStopPort();
    void userSignalSaveDataToFile();
    void Master1On(uint8_t);


private slots:

    void on_userDataCollect_pressed();
    void on_userDataClear_pressed();
    void userInputTableData();
    void userClearTable();
    void userSaveDataToFile();


    void on_buttonMasterOn_pressed();

private:
    Ui::work *ui;

public slots:
    void getSerialPortData(const QByteArray &data, ulong userCounter);
    void getInformPortStatus(uint userPortStatus);
    void Master1Comunication(uint8_t Flag);




};

#endif // WORK_H
