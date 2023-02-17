QT += widgets serialport printsupport

TARGET = terminal
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    work.cpp \
    qcustomplot.cpp \
    powersupply.cpp \
    pack.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    console.h \
    work.h \
    qcustomplot.h \
    powersupply.h \
    pack.h \
    help.h \
    database.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui \
    work.ui \
    powersupply.ui

RESOURCES += \
    terminal.qrc
