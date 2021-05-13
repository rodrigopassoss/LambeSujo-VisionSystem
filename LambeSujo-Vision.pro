#-------------------------------------------------
#
# Project created by QtCreator 2015-09-21T11:37:36
#
#-------------------------------------------------

QT       += core gui serialport



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

TARGET = LambeSujo
#TEMPLATE = app

QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp
QMAKE_CXXFLAGS_RELEASE *= -O3


INCLUDEPATH += /usr/local/include/opencv4
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_features2d -lopencv_calib3d -lopencv_video

INCLUDEPATH += /usr/include/librealsense2
LIBS += -L/usr/local/lib -lrealsense2


#RC_ICONS = gpr.ico

SOURCES += \
    Ball.cpp \
    Build_Robot.cpp \
    Communication.cpp \
    Configurations.cpp \
    Grouping.cpp \
    Robot.cpp \
    Segmentation.cpp \
    constantes_robot.cpp \
    controlador.cpp \
    main.cpp \
    mainwindow.cpp \
    serialcomm.cpp \
    strategy.cpp

HEADERS += \
    Ball.h \
    Build_Robot.h \
    Communication.h \
    Configurations.h \
    Grouping.h \
    Robot.h \
    Segmentation.h \
    constantes_robot.h \
    controlador.h \
    mainwindow.h \
    serialcomm.h \
    strategy.h

FORMS += \
    constantes_robot.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recurso.qrc
