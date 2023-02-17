#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>

#include "qcustomplot.h"//plot
#include <QVector>//data gathering

#include "database.h"


namespace Ui {
class PowerSupply;
}

class PowerSupply : public QWidget
{
    Q_OBJECT



public:
        explicit PowerSupply(QWidget *parent = 0);
        ~PowerSupply();

        QVector<double> x1, y1;
        QVector<double> x2, y2;


        double userTable[NUMBER_POINTS][5];

        uint8_t userRaw;
        uint8_t userColumn;
        uint8_t userFlagPlotRange;
        uint8_t userflagDataClear;
        uint8_t userflagStopPort;

    uint8_t MasterOnFlag2;
    uint8_t MonitorFlag;

    void PowerSupplyInit();
    void Plotting();





signals:
    void Master2On(uint8_t);
    void getData(const QByteArray &data);

private slots:

    void on_buttonMasterOn_pressed();

    void on_buttonCheckFlash_pressed();

    void on_buttonConfigure_pressed();

    void on_buttonStart_pressed();

    void on_buttonStop_pressed();

    void on_sliderNumPoints_valueChanged(int value);

    void on_sliderLIM_I_DAC_valueChanged(int value);

    void on_sliderU_DAC_start_valueChanged(int value);

    void on_sliderU_DAC_stop_valueChanged(int value);

    void on_sliderFlash_valueChanged(int value);

    void on_buttonResult_pressed();

    void on_buttonMonitor_pressed();


private:

    Ui::PowerSupply *ui;
    AnalogTypeDef *as;
    QSerialPort *serial;


public slots:

    void getSerialPortData(const QByteArray &data, ulong userCounter);

    void Master2Comunication(uint8_t Flag);

};









#endif // POWERSUPPLY_H
