QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activzakaz.cpp \
    administrator.cpp \
    adminmodel.cpp \
    buh.cpp \
    buhmodel.cpp \
    cost.cpp \
    db.cpp \
    driver.cpp \
    driverdata.cpp \
    drivermodel.cpp \
    infoorder.cpp \
    main.cpp \
    mainwindow.cpp \
    orderdata.cpp \
    pickdriver.cpp \
    registration.cpp \
    user.cpp \
    usermodel.cpp \
    userworksmodel.cpp

HEADERS += \
    activzakaz.h \
    administrator.h \
    adminmodel.h \
    buh.h \
    buhmodel.h \
    cost.h \
    db.h \
    driver.h \
    driverdata.h \
    drivermodel.h \
    infoorder.h \
    mainwindow.h \
    orderdata.h \
    pickdriver.h \
    registration.h \
    user.h \
    usermodel.h \
    userworksmodel.h

FORMS += \
    administrator.ui \
    buh.ui \
    cost.ui \
    driver.ui \
    infoorder.ui \
    mainwindow.ui \
    pickdriver.ui \
    registration.ui \
    user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
