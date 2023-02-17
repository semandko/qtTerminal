#include "powersupply.h"
#include "ui_powersupply.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QtSerialPort/QSerialPort>

#include <QDebug>

#include "database.h"
#include "pack.h"


//делитель из для слайдеров
const double dividerCurrent         = 100;
const double dividerStart_U         = 10;
const double dividerStop_U          = 100;
const double dividerFlash           = 100;
const double dividerNormal          = 1;

const uint32_t AD7376_NUM_STEPS     = 128;//AD7376 digital potentiometer; <4 MHz


AnalogTypeDef AS[SIZE_SIGNAL];

DefineComplex SOLARCELL;//stm32f100 ADC data in time


uint8_t RXbuffer[16];
uint8_t TXbuffer[16];


void PowerSupply::PowerSupplyInit()
{
    as = &AS[DAC_I];
    as->divider  = &dividerCurrent;

    as = &AS[DAC_U_START];
    as->divider  = &dividerStart_U;

    as = &AS[DAC_U_STOP];
    as->divider   = &dividerStop_U;

    as = &AS[FLASH_INTENCITY];
    as->divider    = &dividerFlash;


    MasterOnFlag2 = 0;
    MonitorFlag = 0;
}




void PowerSupply::Plotting()
{

    userFlagPlotRange = 0;
    userflagDataClear = 0;
    userflagStopPort = 0;
    userColumn = 3;


    //----------Plot--------------------------------------------------------
    ui->Plot_SolarCell->addGraph();
    ui->Plot_SolarCell->xAxis->setLabel("U, V");
    ui->Plot_SolarCell->yAxis->setLabel("I, A");
    ui->Plot_SolarCell->graph(0)->setData(x1,y1);
    ui->Plot_SolarCell->replot();
    //----------Plot--------------------------------------------------------

    //----------Plot--------------------------------------------------------
    ui->Plot_SolarCellEtalon->addGraph();
    ui->Plot_SolarCellEtalon->xAxis->setLabel("Uetalon, V");
    ui->Plot_SolarCellEtalon->yAxis->setLabel("Ietalon, A");
    ui->Plot_SolarCellEtalon->graph(0)->setData(x2,y2);
    ui->Plot_SolarCellEtalon->replot();
    //----------Plot--------------------------------------------------------

}













//main

PowerSupply::PowerSupply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PowerSupply)
{
    ui->setupUi(this);
    PowerSupply::PowerSupplyInit();
    PowerSupply::Plotting();
    PackConfig();



}
PowerSupply::~PowerSupply()
{
    delete ui;
}













void PowerSupply::on_buttonConfigure_pressed()
{
    QByteArray data; //Отсылаемые данные

    //Очистка буфера
    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        TXbuffer[i] = 0;
    }

    //Общий конфигуратор для пакета. Пакет длиной в 16 байт
    TXbuffer[0] = START_FRAME;//передается код двоеточия
    TXbuffer[1] = CONFIGURE;//передается код (0x09)
    TXbuffer[14] = STOP_FRAME;//"Возврат каретки" (0x0D)
    TXbuffer[15] = END_FRAME;// и "Перевод строки" (0x0A)

    //
    AS[FLASH_INTENCITY].code = (uint16_t)AS[FLASH_INTENCITY].value;
    pack(&AS[FLASH_INTENCITY], TXbuffer);

    //
    AS[DAC_U_START].code = (uint16_t)AS[DAC_U_START].value;
    pack(&AS[DAC_U_START], TXbuffer);

    //
    AS[DAC_U_STOP].code = (uint16_t)AS[DAC_U_STOP].value;
    pack(&AS[DAC_U_STOP], TXbuffer);

    //
    AS[DAC_I].code = (uint16_t)AS[DAC_I].value;
    pack(&AS[DAC_I], TXbuffer);

    //
    AS[NUMBER_OF_POINTS].code = (uint16_t)AS[NUMBER_OF_POINTS].value;
    pack(&AS[NUMBER_OF_POINTS], TXbuffer);

    // очистить массив
    data.clear();

    //запаковка данных в массив
    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        data[i] = TXbuffer[i];
    }

    //отправка данных по УАРТ
    //void MainWindow::writeData(const QByteArray &data)
    emit getData(data);
}













//-------------------------------------------------------------------------------------------//
void PowerSupply::on_sliderFlash_valueChanged(int value)
{
    AS[FLASH_INTENCITY].value = (double)value/(*AS[FLASH_INTENCITY].divider);
    ui->flashIntencity->setText(QString("%1").arg(AS[FLASH_INTENCITY].value, 0, 'f', 3));
}
void PowerSupply::on_buttonCheckFlash_pressed()
{
    QByteArray data; //Отсылаемые данные

    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        TXbuffer[i] = 0;
    }

    TXbuffer[0] = START_FRAME;//передается код двоеточия
    TXbuffer[1] = CHECK_FLASH;//передается код двоеточия
    TXbuffer[14] = STOP_FRAME;//"Возврат каретки" (0x0D)
    TXbuffer[15] = END_FRAME;// и "Перевод строки" (0x0A)

    AS[FLASH_INTENCITY].code = (uint16_t)AS[FLASH_INTENCITY].value;
    pack(&AS[FLASH_INTENCITY], TXbuffer);

    qDebug() << "Flash in TXbuffer"<< "TXbuffer[2]"<< TXbuffer[2];
    qDebug() << "Flash in TXbuffer"<< "TXbuffer[3]"<< TXbuffer[3];

    data.clear(); // очистить массив
    //data.length();
    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        data[i] = TXbuffer[i];
    }

    //data.append(ui->configurationView->text());


    //void MainWindow::writeData(const QByteArray &data)
    emit getData(data);
}

//-------------------------------------------------------------------------------------------//





void PowerSupply::on_buttonStart_pressed()
{
    QByteArray data; //Отсылаемые данные

    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        TXbuffer[i] = 0;
    }

    TXbuffer[0] = START_FRAME;//передается код двоеточия
    TXbuffer[1] = START_MEASUREMENT;//передается код
    TXbuffer[14] = STOP_FRAME;//"Возврат каретки" (0x0D)
    TXbuffer[15] = END_FRAME;// и "Перевод строки" (0x0A)

    data.clear(); // очистить массив

    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        data[i] = TXbuffer[i];
    }

    //void MainWindow::writeData(const QByteArray &data)
    emit getData(data);
}




void PowerSupply::on_buttonStop_pressed()
{
    QByteArray data; //Отсылаемые данные

    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        TXbuffer[i] = 0;
    }

    TXbuffer[0] = START_FRAME;//передается код двоеточия
    TXbuffer[1] = STOP_MEASUREMENT;//передается код
    TXbuffer[14] = STOP_FRAME;//"Возврат каретки" (0x0D)
    TXbuffer[15] = END_FRAME;// и "Перевод строки" (0x0A)

    data.clear(); // очистить массив

    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        data[i] = TXbuffer[i];
    }

    //void MainWindow::writeData(const QByteArray &data)
    emit getData(data);
}





void PowerSupply::on_sliderNumPoints_valueChanged(int value)
{
    AS[NUMBER_OF_POINTS].value = value;
    ui->numPoints->setText(QString("%1").arg(value));
}

void PowerSupply::on_sliderLIM_I_DAC_valueChanged(int value)
{
    AS[DAC_I].value = (double)value/(*AS[DAC_I].divider);
    ui->limitI_DAC->setText(QString("%1").arg(AS[DAC_I].value, 0, 'f', 3));
}




void PowerSupply::on_sliderU_DAC_start_valueChanged(int value)
{
    AS[DAC_U_START].value = (double)value/(*AS[DAC_U_START].divider);
    ui->startU_DAC->setText(QString("%1").arg(AS[DAC_U_START].value, 0, 'f', 3));
}

void PowerSupply::on_sliderU_DAC_stop_valueChanged(int value)
{
    AS[DAC_U_STOP].value = (double)value/(*AS[DAC_U_STOP].divider);
    ui->stopU_DAC->setText(QString("%1").arg(AS[DAC_U_STOP].value, 0, 'f', 3));
}


void PowerSupply::on_buttonMonitor_pressed()
{
    QByteArray data; //Отсылаемые данные

    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        TXbuffer[i] = 0;
    }

    if(MonitorFlag == 0)
    {
        TXbuffer[0] = START_FRAME;//передается код двоеточия
        TXbuffer[1] = MONITOR_ON;//передается код
        TXbuffer[14] = STOP_FRAME;//"Возврат каретки" (0x0D)
        TXbuffer[15] = END_FRAME;// и "Перевод строки" (0x0A)
        MonitorFlag = 1;
    } else {
        TXbuffer[0] = START_FRAME;//передается код двоеточия
        TXbuffer[1] = MONITOR_OFF;//передается код
        TXbuffer[14] = STOP_FRAME;//"Возврат каретки" (0x0D)
        TXbuffer[15] = END_FRAME;// и "Перевод строки" (0x0A)
        MonitorFlag = 0;
    }

    data.clear(); // очистить массив

    for (uint8_t i = 0; i < (sizeof(TXbuffer)/sizeof(TXbuffer[0])); i++)
    {
        data[i] = TXbuffer[i];
    }

    //void MainWindow::writeData(const QByteArray &data)
    emit getData(data);
}




void PowerSupply::on_buttonMasterOn_pressed()
{
    ui->buttonMasterOn->setStyleSheet("background-color: green;");
    emit Master2On(2);
}

void PowerSupply::Master2Comunication(uint8_t Flag)
{
    if(Flag == 2)
    {
        MasterOnFlag2 = 1;
    } else {
        MasterOnFlag2 = 0;
        ui->buttonMasterOn->setStyleSheet("background-color: #f0f0f0;");
    }
}




void PowerSupply::on_buttonResult_pressed()
{
    ui->viewerU_OC->setText(QString("%1").arg(AS[ADC_U].valuemeasured, 0, 'f', 3));
    ui->viewerI_SC->setText(QString("%1").arg(AS[ADC_I].valuemeasured, 0, 'f', 3));
    ui->viewerReferenceU->setText(QString("%1").arg(AS[REFERENCE_U].valuemeasured, 0, 'f', 3));
    ui->Status_Result->setStyleSheet("background-color: green;");
}

























//
//console выпустит сигнал
//emit sendSerialPortData(data, data.length());
//slot его заберет
void PowerSupply::getSerialPortData(const QByteArray &data, ulong userCounter)
{
    uint8_t codeForCase;

    ui->Status_CheckFlash->setStyleSheet("background-color: #f0f0f0;");
    ui->Status_Config->setStyleSheet("background-color: #f0f0f0;");
    ui->Status_Start->setStyleSheet("background-color: #f0f0f0;");
    ui->Status_Stop->setStyleSheet("background-color: #f0f0f0;");
    ui->Status_Result->setStyleSheet("background-color: #f0f0f0;");

    if (userCounter == 16)
    {
        for(uint8_t i = 0; i < userCounter; i++)
        {
            RXbuffer[i] = data[i];
        }

        if(RXbuffer[0]==START_FRAME)//
        {
            codeForCase = RXbuffer[1];
            //0x3A - START_FRAME
            //0x0D - STOP_FRAME
            //0x0A - END_FRAME

            //0x01 - START_MEASUREMENT
            //0x02 - STOP_MEASUREMENT
            //0x03 - CHECK_FLASH
            //0x04 - SAVE_RESULTS
            //0x05 - MONITOR_ON
            //0x06 - MONITOR_OFF
            //0x07 -
            //0x08 -
            //0x09 - CONFIGURE

            //0x11 - START_MEASUREMENT_OK
            //0x21 - STOP_MEASUREMENT_OK
            //0x31 - CHECK_FLASH_OK
            //0x41 - SAVE_RESULTS_OK
            //0x51 - MONITOR_ON_OK
            //0x61 - MONITOR_OFF_OK
            //0x91 - CONFIGURE_OK

            if((codeForCase != MONITOR_ON)||(codeForCase != MONITOR_ON_OK)||(codeForCase != MONITOR_OFF)||(codeForCase != MONITOR_OFF_OK))
            {
                ui->buttonMonitor->setStyleSheet("background-color: #f0f0f0;");
            }

            switch (codeForCase)
            {


            case CHECK_FLASH://для проверки сам на себя, так как контролер даст ответ CHECK_FLASH_OK
                unpack(&AS[FLASH_INTENCITY], RXbuffer);
                ui->Status_CheckFlash->setStyleSheet("background-color: green;");
                //то что отправили то и должны получить
                ui->configurationView->setText(QString("%1").arg(AS[FLASH_INTENCITY].valuemeasured, 0, 'f', 3));//
                break;
            case CHECK_FLASH_OK://ответ по UART
                ui->Status_CheckFlash->setStyleSheet("background-color: green;");
                break;



            case CONFIGURE://для проверки сам на себя
                unpack(&AS[FLASH_INTENCITY],    RXbuffer);
                unpack(&AS[DAC_U_START],        RXbuffer);
                unpack(&AS[DAC_U_STOP],         RXbuffer);
                unpack(&AS[DAC_I],              RXbuffer);
                unpack(&AS[NUMBER_OF_POINTS],   RXbuffer);
                ui->Status_Config->setStyleSheet("background-color: green;");
                break;
            case CONFIGURE_OK://ответ по UART
                ui->Status_Config->setStyleSheet("background-color: green;");
                break;




            case START_MEASUREMENT://для проверки сам на себя
                ui->Status_Start->setStyleSheet("background-color: green;");
                break;
            case START_MEASUREMENT_OK://ответ по UART
                ui->Status_Start->setStyleSheet("background-color: green;");
                break;



            case STOP_MEASUREMENT://для проверки сам на себя
                unpack(&AS[ADC_U],        RXbuffer);//1
                unpack(&AS[ADC_I],        RXbuffer);//2
                unpack(&AS[LIM_I],        RXbuffer);//4
                unpack(&AS[REFERENCE_U],  RXbuffer);//5
                unpack(&AS[TIME_TICK],    RXbuffer);//6
                ui->Status_Stop->setStyleSheet("background-color: green;");
                break;
            case STOP_MEASUREMENT_OK://ответ по UART
                unpack(&AS[ADC_U],        RXbuffer);//1
                unpack(&AS[ADC_I],        RXbuffer);//2
                unpack(&AS[LIM_I],        RXbuffer);//4
                unpack(&AS[REFERENCE_U],  RXbuffer);//5
                unpack(&AS[TIME_TICK],    RXbuffer);//6
                ui->Status_Stop->setStyleSheet("background-color: green;");
                break;



            case SAVE_RESULTS://для проверки сам на себя

                break;
            case SAVE_RESULTS_OK://ответ по UART

                break;




            case MONITOR_ON://для проверки сам на себя
                unpack(&AS[ADC_U],        RXbuffer);//1
                unpack(&AS[ADC_I],        RXbuffer);//2
                unpack(&AS[REFERENCE_U],  RXbuffer);//5
                unpack(&AS[LUXMETER1_LUX], RXbuffer);//3
                ui->buttonMonitor->setStyleSheet("background-color: green;");
                ui->ADC_UOC->setText(QString("%1").arg(AS[ADC_U].valuemeasured, 0, 'f', 3));
                ui->ADC_I->setText(QString("%1").arg(AS[ADC_I].valuemeasured, 0, 'f', 3));
                ui->viewerReferenceU->setText(QString("%1").arg(AS[REFERENCE_U].valuemeasured, 0, 'f', 3));
                ui->Light_Intensity->setText(QString("%1").arg(AS[LUXMETER1_LUX].valuemeasured, 0, 'f', 3));
                break;
            case MONITOR_ON_OK://
                unpack(&AS[ADC_U],        RXbuffer);//1
                unpack(&AS[ADC_I],        RXbuffer);//2
                unpack(&AS[REFERENCE_U],  RXbuffer);//5
                unpack(&AS[LUXMETER1_LUX], RXbuffer);//3
                ui->buttonMonitor->setStyleSheet("background-color: green;");              
                ui->ADC_UOC->setText(QString("%1").arg(AS[ADC_U].valuemeasured, 0, 'f', 3));
                ui->ADC_I->setText(QString("%1").arg(AS[ADC_I].valuemeasured, 0, 'f', 3));
                ui->viewerReferenceU->setText(QString("%1").arg(AS[REFERENCE_U].valuemeasured, 0, 'f', 3));
                ui->Light_Intensity->setText(QString("%1").arg(AS[LUXMETER1_LUX].valuemeasured, 0, 'f', 3));


            case MONITOR_OFF://для проверки сам на себя
                ui->buttonMonitor->setStyleSheet("background-color: red;");
                break;
            case MONITOR_OFF_OK://
                ui->buttonMonitor->setStyleSheet("background-color: #f0f0f0;");
                break;




            default:
                break;

            }
        }
    }
}


