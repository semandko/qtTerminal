/********************************************************************************
** Form generated from reading UI file 'powersupply.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERSUPPLY_H
#define UI_POWERSUPPLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_PowerSupply
{
public:
    QPushButton *buttonCheckFlash;
    QLineEdit *flashIntencity;
    QLabel *Flash_Light;
    QPushButton *buttonConfigure;
    QPushButton *buttonStart;
    QLabel *statusPortInform;
    QLineEdit *startU_DAC;
    QLabel *Start_DAC_U;
    QLineEdit *limitI_DAC;
    QLabel *Start_DAC_I;
    QLineEdit *stopU_DAC;
    QLabel *Stop_DAC_U;
    QLabel *Status_Port;
    QPushButton *buttonMasterOn;
    QLabel *Number_Point;
    QLineEdit *numPoints;
    QPushButton *buttonStop;
    QSlider *sliderU_DAC_start;
    QSlider *sliderU_DAC_stop;
    QSlider *sliderLIM_I_DAC;
    QSlider *sliderNumPoints;
    QTimeEdit *timeEdit;
    QSlider *sliderFlash;
    QCustomPlot *Plot_SolarCell;
    QFrame *frame_5;
    QLineEdit *configurationView;
    QLineEdit *viewerU_OC;
    QLabel *Value_UOC;
    QLineEdit *viewerI_SC;
    QLabel *Value_ISC;
    QLineEdit *viewerFF;
    QLabel *Value_UOCetalon;
    QLineEdit *viewerEfficiency;
    QLabel *Value_ISCetalon;
    QLineEdit *viewerU_OC_etalon;
    QLabel *Value_FFetalon;
    QLineEdit *viewerI_SC_etalon;
    QLabel *Value_Eff_etalon;
    QLineEdit *viewerFF_etalon;
    QLabel *Value_FF;
    QLineEdit *viewerEfficiency_etalon;
    QLabel *Value_Efficiency;
    QLineEdit *viewerIntencity;
    QLabel *Value_lightIntencity;
    QLabel *Value_Temperature;
    QLineEdit *viewerTemperature;
    QCustomPlot *Plot_SolarCellEtalon;
    QFrame *frame_6;
    QLineEdit *viewerPowerLight;
    QLabel *Value_PowerLight;
    QLineEdit *viewerStatusPort;
    QPushButton *buttonResult;
    QLineEdit *viewerReferenceU;
    QLabel *Value_RefVoltage;
    QLabel *Status_Config;
    QLabel *Status_Start;
    QLabel *Status_Stop;
    QLabel *Status_Result;
    QLabel *Status_CheckFlash;
    QLineEdit *ADC_UOC;
    QLineEdit *ADC_I;
    QLineEdit *Light_Intensity;
    QPushButton *buttonMonitor;
    QLabel *Status_Monitor;
    QLabel *Status_Monitor_U;
    QLabel *Status_Monitor_I;
    QLabel *Status_Monitor_Light;

    void setupUi(QWidget *PowerSupply)
    {
        if (PowerSupply->objectName().isEmpty())
            PowerSupply->setObjectName(QStringLiteral("PowerSupply"));
        PowerSupply->resize(1015, 552);
        buttonCheckFlash = new QPushButton(PowerSupply);
        buttonCheckFlash->setObjectName(QStringLiteral("buttonCheckFlash"));
        buttonCheckFlash->setGeometry(QRect(150, 60, 75, 23));
        flashIntencity = new QLineEdit(PowerSupply);
        flashIntencity->setObjectName(QStringLiteral("flashIntencity"));
        flashIntencity->setGeometry(QRect(20, 60, 113, 20));
        Flash_Light = new QLabel(PowerSupply);
        Flash_Light->setObjectName(QStringLiteral("Flash_Light"));
        Flash_Light->setGeometry(QRect(20, 20, 121, 16));
        buttonConfigure = new QPushButton(PowerSupply);
        buttonConfigure->setObjectName(QStringLiteral("buttonConfigure"));
        buttonConfigure->setGeometry(QRect(20, 509, 75, 23));
        buttonStart = new QPushButton(PowerSupply);
        buttonStart->setObjectName(QStringLiteral("buttonStart"));
        buttonStart->setGeometry(QRect(103, 509, 75, 23));
        statusPortInform = new QLabel(PowerSupply);
        statusPortInform->setObjectName(QStringLiteral("statusPortInform"));
        statusPortInform->setGeometry(QRect(930, 10, 47, 13));
        startU_DAC = new QLineEdit(PowerSupply);
        startU_DAC->setObjectName(QStringLiteral("startU_DAC"));
        startU_DAC->setGeometry(QRect(20, 190, 113, 20));
        Start_DAC_U = new QLabel(PowerSupply);
        Start_DAC_U->setObjectName(QStringLiteral("Start_DAC_U"));
        Start_DAC_U->setGeometry(QRect(20, 160, 61, 16));
        limitI_DAC = new QLineEdit(PowerSupply);
        limitI_DAC->setObjectName(QStringLiteral("limitI_DAC"));
        limitI_DAC->setGeometry(QRect(20, 290, 113, 20));
        Start_DAC_I = new QLabel(PowerSupply);
        Start_DAC_I->setObjectName(QStringLiteral("Start_DAC_I"));
        Start_DAC_I->setGeometry(QRect(20, 260, 111, 16));
        stopU_DAC = new QLineEdit(PowerSupply);
        stopU_DAC->setObjectName(QStringLiteral("stopU_DAC"));
        stopU_DAC->setGeometry(QRect(150, 190, 113, 20));
        Stop_DAC_U = new QLabel(PowerSupply);
        Stop_DAC_U->setObjectName(QStringLiteral("Stop_DAC_U"));
        Stop_DAC_U->setGeometry(QRect(150, 160, 61, 16));
        Status_Port = new QLabel(PowerSupply);
        Status_Port->setObjectName(QStringLiteral("Status_Port"));
        Status_Port->setGeometry(QRect(860, 10, 61, 16));
        buttonMasterOn = new QPushButton(PowerSupply);
        buttonMasterOn->setObjectName(QStringLiteral("buttonMasterOn"));
        buttonMasterOn->setGeometry(QRect(920, 40, 75, 23));
        Number_Point = new QLabel(PowerSupply);
        Number_Point->setObjectName(QStringLiteral("Number_Point"));
        Number_Point->setGeometry(QRect(150, 260, 61, 16));
        numPoints = new QLineEdit(PowerSupply);
        numPoints->setObjectName(QStringLiteral("numPoints"));
        numPoints->setGeometry(QRect(150, 290, 113, 20));
        buttonStop = new QPushButton(PowerSupply);
        buttonStop->setObjectName(QStringLiteral("buttonStop"));
        buttonStop->setGeometry(QRect(189, 509, 75, 23));
        sliderU_DAC_start = new QSlider(PowerSupply);
        sliderU_DAC_start->setObjectName(QStringLiteral("sliderU_DAC_start"));
        sliderU_DAC_start->setGeometry(QRect(20, 140, 111, 19));
        sliderU_DAC_start->setMaximum(100);
        sliderU_DAC_start->setPageStep(5);
        sliderU_DAC_start->setOrientation(Qt::Horizontal);
        sliderU_DAC_stop = new QSlider(PowerSupply);
        sliderU_DAC_stop->setObjectName(QStringLiteral("sliderU_DAC_stop"));
        sliderU_DAC_stop->setGeometry(QRect(150, 140, 111, 19));
        sliderU_DAC_stop->setMaximum(2000);
        sliderU_DAC_stop->setPageStep(5);
        sliderU_DAC_stop->setOrientation(Qt::Horizontal);
        sliderLIM_I_DAC = new QSlider(PowerSupply);
        sliderLIM_I_DAC->setObjectName(QStringLiteral("sliderLIM_I_DAC"));
        sliderLIM_I_DAC->setGeometry(QRect(20, 240, 111, 19));
        sliderLIM_I_DAC->setMaximum(2000);
        sliderLIM_I_DAC->setSingleStep(1);
        sliderLIM_I_DAC->setPageStep(10);
        sliderLIM_I_DAC->setOrientation(Qt::Horizontal);
        sliderNumPoints = new QSlider(PowerSupply);
        sliderNumPoints->setObjectName(QStringLiteral("sliderNumPoints"));
        sliderNumPoints->setGeometry(QRect(150, 240, 111, 19));
        sliderNumPoints->setMaximum(4095);
        sliderNumPoints->setOrientation(Qt::Horizontal);
        timeEdit = new QTimeEdit(PowerSupply);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(868, 509, 118, 22));
        sliderFlash = new QSlider(PowerSupply);
        sliderFlash->setObjectName(QStringLiteral("sliderFlash"));
        sliderFlash->setGeometry(QRect(20, 40, 111, 19));
        sliderFlash->setMaximum(12700);
        sliderFlash->setOrientation(Qt::Horizontal);
        Plot_SolarCell = new QCustomPlot(PowerSupply);
        Plot_SolarCell->setObjectName(QStringLiteral("Plot_SolarCell"));
        Plot_SolarCell->setGeometry(QRect(370, 30, 351, 221));
        frame_5 = new QFrame(Plot_SolarCell);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(0, -10, 351, 241));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Raised);
        configurationView = new QLineEdit(PowerSupply);
        configurationView->setObjectName(QStringLiteral("configurationView"));
        configurationView->setGeometry(QRect(920, 90, 71, 361));
        viewerU_OC = new QLineEdit(PowerSupply);
        viewerU_OC->setObjectName(QStringLiteral("viewerU_OC"));
        viewerU_OC->setGeometry(QRect(835, 91, 71, 20));
        viewerU_OC->setMaximumSize(QSize(71, 16777215));
        Value_UOC = new QLabel(PowerSupply);
        Value_UOC->setObjectName(QStringLiteral("Value_UOC"));
        Value_UOC->setGeometry(QRect(742, 94, 47, 13));
        viewerI_SC = new QLineEdit(PowerSupply);
        viewerI_SC->setObjectName(QStringLiteral("viewerI_SC"));
        viewerI_SC->setGeometry(QRect(835, 121, 71, 20));
        viewerI_SC->setMaximumSize(QSize(71, 16777215));
        Value_ISC = new QLabel(PowerSupply);
        Value_ISC->setObjectName(QStringLiteral("Value_ISC"));
        Value_ISC->setGeometry(QRect(742, 125, 47, 13));
        viewerFF = new QLineEdit(PowerSupply);
        viewerFF->setObjectName(QStringLiteral("viewerFF"));
        viewerFF->setGeometry(QRect(835, 151, 71, 20));
        viewerFF->setMaximumSize(QSize(71, 16777215));
        Value_UOCetalon = new QLabel(PowerSupply);
        Value_UOCetalon->setObjectName(QStringLiteral("Value_UOCetalon"));
        Value_UOCetalon->setGeometry(QRect(742, 217, 64, 13));
        viewerEfficiency = new QLineEdit(PowerSupply);
        viewerEfficiency->setObjectName(QStringLiteral("viewerEfficiency"));
        viewerEfficiency->setGeometry(QRect(835, 181, 71, 20));
        viewerEfficiency->setMaximumSize(QSize(71, 16777215));
        Value_ISCetalon = new QLabel(PowerSupply);
        Value_ISCetalon->setObjectName(QStringLiteral("Value_ISCetalon"));
        Value_ISCetalon->setGeometry(QRect(742, 247, 59, 13));
        viewerU_OC_etalon = new QLineEdit(PowerSupply);
        viewerU_OC_etalon->setObjectName(QStringLiteral("viewerU_OC_etalon"));
        viewerU_OC_etalon->setGeometry(QRect(835, 211, 71, 20));
        viewerU_OC_etalon->setMaximumSize(QSize(71, 16777215));
        Value_FFetalon = new QLabel(PowerSupply);
        Value_FFetalon->setObjectName(QStringLiteral("Value_FFetalon"));
        Value_FFetalon->setGeometry(QRect(742, 275, 48, 13));
        viewerI_SC_etalon = new QLineEdit(PowerSupply);
        viewerI_SC_etalon->setObjectName(QStringLiteral("viewerI_SC_etalon"));
        viewerI_SC_etalon->setGeometry(QRect(835, 241, 71, 20));
        viewerI_SC_etalon->setMaximumSize(QSize(71, 16777215));
        Value_Eff_etalon = new QLabel(PowerSupply);
        Value_Eff_etalon->setObjectName(QStringLiteral("Value_Eff_etalon"));
        Value_Eff_etalon->setGeometry(QRect(742, 309, 58, 13));
        viewerFF_etalon = new QLineEdit(PowerSupply);
        viewerFF_etalon->setObjectName(QStringLiteral("viewerFF_etalon"));
        viewerFF_etalon->setGeometry(QRect(835, 271, 71, 20));
        viewerFF_etalon->setMaximumSize(QSize(71, 16777215));
        Value_FF = new QLabel(PowerSupply);
        Value_FF->setObjectName(QStringLiteral("Value_FF"));
        Value_FF->setGeometry(QRect(742, 158, 12, 13));
        viewerEfficiency_etalon = new QLineEdit(PowerSupply);
        viewerEfficiency_etalon->setObjectName(QStringLiteral("viewerEfficiency_etalon"));
        viewerEfficiency_etalon->setGeometry(QRect(835, 301, 71, 20));
        viewerEfficiency_etalon->setMaximumSize(QSize(71, 16777215));
        Value_Efficiency = new QLabel(PowerSupply);
        Value_Efficiency->setObjectName(QStringLiteral("Value_Efficiency"));
        Value_Efficiency->setGeometry(QRect(742, 188, 47, 13));
        viewerIntencity = new QLineEdit(PowerSupply);
        viewerIntencity->setObjectName(QStringLiteral("viewerIntencity"));
        viewerIntencity->setGeometry(QRect(833, 331, 71, 20));
        viewerIntencity->setMaximumSize(QSize(71, 16777215));
        Value_lightIntencity = new QLabel(PowerSupply);
        Value_lightIntencity->setObjectName(QStringLiteral("Value_lightIntencity"));
        Value_lightIntencity->setGeometry(QRect(740, 337, 67, 13));
        Value_Temperature = new QLabel(PowerSupply);
        Value_Temperature->setObjectName(QStringLiteral("Value_Temperature"));
        Value_Temperature->setGeometry(QRect(740, 369, 62, 13));
        viewerTemperature = new QLineEdit(PowerSupply);
        viewerTemperature->setObjectName(QStringLiteral("viewerTemperature"));
        viewerTemperature->setGeometry(QRect(833, 361, 71, 20));
        viewerTemperature->setMaximumSize(QSize(71, 16777215));
        Plot_SolarCellEtalon = new QCustomPlot(PowerSupply);
        Plot_SolarCellEtalon->setObjectName(QStringLiteral("Plot_SolarCellEtalon"));
        Plot_SolarCellEtalon->setGeometry(QRect(370, 270, 351, 221));
        frame_6 = new QFrame(Plot_SolarCellEtalon);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(0, 0, 351, 241));
        frame_6->setFrameShape(QFrame::Panel);
        frame_6->setFrameShadow(QFrame::Raised);
        viewerPowerLight = new QLineEdit(PowerSupply);
        viewerPowerLight->setObjectName(QStringLiteral("viewerPowerLight"));
        viewerPowerLight->setGeometry(QRect(833, 391, 71, 20));
        viewerPowerLight->setMaximumSize(QSize(71, 16777215));
        Value_PowerLight = new QLabel(PowerSupply);
        Value_PowerLight->setObjectName(QStringLiteral("Value_PowerLight"));
        Value_PowerLight->setGeometry(QRect(740, 400, 66, 13));
        viewerStatusPort = new QLineEdit(PowerSupply);
        viewerStatusPort->setObjectName(QStringLiteral("viewerStatusPort"));
        viewerStatusPort->setGeometry(QRect(920, 10, 71, 20));
        buttonResult = new QPushButton(PowerSupply);
        buttonResult->setObjectName(QStringLiteral("buttonResult"));
        buttonResult->setGeometry(QRect(279, 509, 75, 23));
        viewerReferenceU = new QLineEdit(PowerSupply);
        viewerReferenceU->setObjectName(QStringLiteral("viewerReferenceU"));
        viewerReferenceU->setGeometry(QRect(833, 424, 71, 20));
        viewerReferenceU->setMaximumSize(QSize(71, 16777215));
        Value_RefVoltage = new QLabel(PowerSupply);
        Value_RefVoltage->setObjectName(QStringLiteral("Value_RefVoltage"));
        Value_RefVoltage->setGeometry(QRect(740, 430, 89, 13));
        Status_Config = new QLabel(PowerSupply);
        Status_Config->setObjectName(QStringLiteral("Status_Config"));
        Status_Config->setGeometry(QRect(48, 490, 16, 13));
        Status_Start = new QLabel(PowerSupply);
        Status_Start->setObjectName(QStringLiteral("Status_Start"));
        Status_Start->setGeometry(QRect(135, 490, 13, 13));
        Status_Stop = new QLabel(PowerSupply);
        Status_Stop->setObjectName(QStringLiteral("Status_Stop"));
        Status_Stop->setGeometry(QRect(220, 490, 13, 13));
        Status_Result = new QLabel(PowerSupply);
        Status_Result->setObjectName(QStringLiteral("Status_Result"));
        Status_Result->setGeometry(QRect(310, 490, 13, 13));
        Status_CheckFlash = new QLabel(PowerSupply);
        Status_CheckFlash->setObjectName(QStringLiteral("Status_CheckFlash"));
        Status_CheckFlash->setGeometry(QRect(179, 40, 13, 13));
        ADC_UOC = new QLineEdit(PowerSupply);
        ADC_UOC->setObjectName(QStringLiteral("ADC_UOC"));
        ADC_UOC->setGeometry(QRect(20, 390, 61, 20));
        ADC_I = new QLineEdit(PowerSupply);
        ADC_I->setObjectName(QStringLiteral("ADC_I"));
        ADC_I->setGeometry(QRect(110, 390, 61, 20));
        Light_Intensity = new QLineEdit(PowerSupply);
        Light_Intensity->setObjectName(QStringLiteral("Light_Intensity"));
        Light_Intensity->setGeometry(QRect(200, 390, 61, 20));
        buttonMonitor = new QPushButton(PowerSupply);
        buttonMonitor->setObjectName(QStringLiteral("buttonMonitor"));
        buttonMonitor->setGeometry(QRect(103, 440, 75, 23));
        Status_Monitor = new QLabel(PowerSupply);
        Status_Monitor->setObjectName(QStringLiteral("Status_Monitor"));
        Status_Monitor->setGeometry(QRect(120, 420, 47, 13));
        Status_Monitor_U = new QLabel(PowerSupply);
        Status_Monitor_U->setObjectName(QStringLiteral("Status_Monitor_U"));
        Status_Monitor_U->setGeometry(QRect(37, 370, 20, 13));
        Status_Monitor_I = new QLabel(PowerSupply);
        Status_Monitor_I->setObjectName(QStringLiteral("Status_Monitor_I"));
        Status_Monitor_I->setGeometry(QRect(128, 370, 18, 13));
        Status_Monitor_Light = new QLabel(PowerSupply);
        Status_Monitor_Light->setObjectName(QStringLiteral("Status_Monitor_Light"));
        Status_Monitor_Light->setGeometry(QRect(216, 370, 22, 13));

        retranslateUi(PowerSupply);

        QMetaObject::connectSlotsByName(PowerSupply);
    } // setupUi

    void retranslateUi(QWidget *PowerSupply)
    {
        PowerSupply->setWindowTitle(QApplication::translate("PowerSupply", "Form", 0));
        buttonCheckFlash->setText(QApplication::translate("PowerSupply", "CheckFlash", 0));
        Flash_Light->setText(QApplication::translate("PowerSupply", "Flash Light Intencity, ms", 0));
        buttonConfigure->setText(QApplication::translate("PowerSupply", "Configure", 0));
        buttonStart->setText(QApplication::translate("PowerSupply", "Start", 0));
        statusPortInform->setText(QString());
        startU_DAC->setText(QString());
        Start_DAC_U->setText(QApplication::translate("PowerSupply", "Start: U, V", 0));
        Start_DAC_I->setText(QApplication::translate("PowerSupply", "Limit max current: I, A", 0));
        Stop_DAC_U->setText(QApplication::translate("PowerSupply", "Stop: U, V", 0));
        Status_Port->setText(QApplication::translate("PowerSupply", "StatusPort", 0));
        buttonMasterOn->setText(QApplication::translate("PowerSupply", "MasterOn", 0));
        Number_Point->setText(QApplication::translate("PowerSupply", "Num: Points", 0));
        buttonStop->setText(QApplication::translate("PowerSupply", "Stop", 0));
        Value_UOC->setText(QApplication::translate("PowerSupply", "U_OC", 0));
        Value_ISC->setText(QApplication::translate("PowerSupply", "I_SC", 0));
        Value_UOCetalon->setText(QApplication::translate("PowerSupply", "U_OC_etalon", 0));
        Value_ISCetalon->setText(QApplication::translate("PowerSupply", "I_SC_etalon", 0));
        Value_FFetalon->setText(QApplication::translate("PowerSupply", "FF_etalon", 0));
        Value_Eff_etalon->setText(QApplication::translate("PowerSupply", "Efficiency_e", 0));
        Value_FF->setText(QApplication::translate("PowerSupply", "FF", 0));
        Value_Efficiency->setText(QApplication::translate("PowerSupply", "Efficiency", 0));
        Value_lightIntencity->setText(QApplication::translate("PowerSupply", "Light intencity", 0));
        Value_Temperature->setText(QApplication::translate("PowerSupply", "Temperature", 0));
        Value_PowerLight->setText(QApplication::translate("PowerSupply", "Power of light", 0));
        buttonResult->setText(QApplication::translate("PowerSupply", "Result", 0));
        Value_RefVoltage->setText(QApplication::translate("PowerSupply", "Reference voltage", 0));
        Status_Config->setText(QApplication::translate("PowerSupply", " Ok", 0));
        Status_Start->setText(QApplication::translate("PowerSupply", "Ok", 0));
        Status_Stop->setText(QApplication::translate("PowerSupply", "Ok", 0));
        Status_Result->setText(QApplication::translate("PowerSupply", "Ok", 0));
        Status_CheckFlash->setText(QApplication::translate("PowerSupply", "Ok", 0));
        buttonMonitor->setText(QApplication::translate("PowerSupply", "Monitor", 0));
        Status_Monitor->setText(QApplication::translate("PowerSupply", "ON/OFF", 0));
        Status_Monitor_U->setText(QApplication::translate("PowerSupply", "U, V", 0));
        Status_Monitor_I->setText(QApplication::translate("PowerSupply", "I, A", 0));
        Status_Monitor_Light->setText(QApplication::translate("PowerSupply", "L, W", 0));
    } // retranslateUi

};

namespace Ui {
    class PowerSupply: public Ui_PowerSupply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERSUPPLY_H
