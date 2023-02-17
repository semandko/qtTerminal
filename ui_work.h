/********************************************************************************
** Form generated from reading UI file 'work.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORK_H
#define UI_WORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_work
{
public:
    QLabel *workOut;
    QLCDNumber *lcdN_1;
    QLCDNumber *lcdTimer;
    QPushButton *userDataCollect;
    QLabel *userTimersViewer;
    QCustomPlot *customPlot;
    QFrame *frame_5;
    QPushButton *userDataClear;
    QTableWidget *usertableWidget;
    QFrame *userComunications;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QPushButton *userSendToSerial;
    QPushButton *pushButton_2;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QLabel *userDataReady;
    QFrame *frame_4;
    QLabel *userPortStatus;
    QPushButton *buttonMasterOn;

    void setupUi(QWidget *work)
    {
        if (work->objectName().isEmpty())
            work->setObjectName(QStringLiteral("work"));
        work->resize(625, 487);
        workOut = new QLabel(work);
        workOut->setObjectName(QStringLiteral("workOut"));
        workOut->setGeometry(QRect(60, 40, 128, 19));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        workOut->setFont(font);
        lcdN_1 = new QLCDNumber(work);
        lcdN_1->setObjectName(QStringLiteral("lcdN_1"));
        lcdN_1->setGeometry(QRect(20, 70, 201, 81));
        lcdTimer = new QLCDNumber(work);
        lcdTimer->setObjectName(QStringLiteral("lcdTimer"));
        lcdTimer->setGeometry(QRect(20, 210, 201, 81));
        userDataCollect = new QPushButton(work);
        userDataCollect->setObjectName(QStringLiteral("userDataCollect"));
        userDataCollect->setGeometry(QRect(435, 437, 75, 23));
        userTimersViewer = new QLabel(work);
        userTimersViewer->setObjectName(QStringLiteral("userTimersViewer"));
        userTimersViewer->setGeometry(QRect(101, 187, 47, 13));
        userTimersViewer->setMaximumSize(QSize(16777209, 16777215));
        userTimersViewer->setFont(font);
        customPlot = new QCustomPlot(work);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(270, 70, 310, 220));
        frame_5 = new QFrame(customPlot);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(0, -20, 331, 241));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Raised);
        userDataClear = new QPushButton(work);
        userDataClear->setObjectName(QStringLiteral("userDataClear"));
        userDataClear->setGeometry(QRect(515, 437, 75, 23));
        usertableWidget = new QTableWidget(work);
        if (usertableWidget->columnCount() < 3)
            usertableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usertableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usertableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        usertableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (usertableWidget->rowCount() < 2)
            usertableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        usertableWidget->setObjectName(QStringLiteral("usertableWidget"));
        usertableWidget->setGeometry(QRect(261, 300, 331, 101));
        userComunications = new QFrame(work);
        userComunications->setObjectName(QStringLiteral("userComunications"));
        userComunications->setGeometry(QRect(10, 310, 221, 151));
        userComunications->setFrameShape(QFrame::Panel);
        userComunications->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(userComunications);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(42, 5, 147, 13));
        label_3 = new QLabel(userComunications);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(7, 64, 115, 13));
        layoutWidget = new QWidget(userComunications);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(133, 60, 83, 77));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        userSendToSerial = new QPushButton(layoutWidget);
        userSendToSerial->setObjectName(QStringLiteral("userSendToSerial"));

        verticalLayout->addWidget(userSendToSerial);

        pushButton_2 = new QPushButton(userComunications);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(124, 30, 92, 23));
        frame = new QFrame(work);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 30, 221, 131));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(work);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 179, 221, 121));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(work);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(260, 424, 81, 36));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        userDataReady = new QLabel(frame_3);
        userDataReady->setObjectName(QStringLiteral("userDataReady"));
        userDataReady->setGeometry(QRect(10, 10, 61, 16));
        frame_4 = new QFrame(work);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(420, 10, 91, 29));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Raised);
        userPortStatus = new QLabel(frame_4);
        userPortStatus->setObjectName(QStringLiteral("userPortStatus"));
        userPortStatus->setGeometry(QRect(0, 4, 81, 21));
        QFont font1;
        font1.setPointSize(10);
        userPortStatus->setFont(font1);
        buttonMasterOn = new QPushButton(work);
        buttonMasterOn->setObjectName(QStringLiteral("buttonMasterOn"));
        buttonMasterOn->setGeometry(QRect(530, 10, 75, 23));

        retranslateUi(work);

        QMetaObject::connectSlotsByName(work);
    } // setupUi

    void retranslateUi(QWidget *work)
    {
        work->setWindowTitle(QApplication::translate("work", "Form", Q_NULLPTR));
        workOut->setText(QApplication::translate("work", "Serial port data", Q_NULLPTR));
        userDataCollect->setText(QApplication::translate("work", "Data Save", Q_NULLPTR));
        userTimersViewer->setText(QApplication::translate("work", "Timers", Q_NULLPTR));
        userDataClear->setText(QApplication::translate("work", "Data Clear", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = usertableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("work", "N", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = usertableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("work", "X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = usertableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("work", "Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = usertableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("work", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = usertableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("work", "1", Q_NULLPTR));
        label_2->setText(QApplication::translate("work", "Communication with Serial Port", Q_NULLPTR));
        label_3->setText(QApplication::translate("work", "Speed of data collecting", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("work", "1 ms", Q_NULLPTR)
         << QApplication::translate("work", "2 ms", Q_NULLPTR)
         << QApplication::translate("work", "5 ms", Q_NULLPTR)
         << QApplication::translate("work", "10 ms", Q_NULLPTR)
        );
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("work", "Monitor On", Q_NULLPTR)
         << QApplication::translate("work", "Monitor Off", Q_NULLPTR)
        );
        userSendToSerial->setText(QApplication::translate("work", "Send to Serial", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("work", "RealTimeMeasure", Q_NULLPTR));
        userDataReady->setText(QApplication::translate("work", "Data Ready", Q_NULLPTR));
        userPortStatus->setText(QApplication::translate("work", "   Port Status", Q_NULLPTR));
        buttonMasterOn->setText(QApplication::translate("work", "MasterOn", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class work: public Ui_work {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORK_H
