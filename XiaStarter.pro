#-------------------------------------------------
#
# Project created by QtCreator 2012-11-12T10:15:39
#
#-------------------------------------------------

QT       += core gui

TARGET = xiaStarter
TEMPLATE = app


SOURCES += src/main.cpp\
        src/xiastarterwindow.cpp \
    src/xiastarter.cpp \
    src/sourceconfdialog.cpp \
    src/about.cpp \
    src/xs_det.cpp \
    src/qcustomplot.cpp \
    src/preferencedialog.cpp \
    src/xs_info.cpp \
    src/dgfconfig.cpp \
    src/psasettings.cpp

HEADERS  += src/xiastarterwindow.h \
    src/xiastarter.h \
    src/sourceconfdialog.h \
    src/about.h \
    src/xs_det.h \
    src/qcustomplot.h \
    src/preferencedialog.h \
    src/xs_info.h \
    src/dgfconfig.h \
    src/psasettings.h

FORMS    += src/xiastarterwindow.ui \
    src/sourceconfdialog.ui \
    src/about.ui \
    src/preferencedialog.ui \
    src/dgfconfig.ui \
    src/psasettings.ui

OTHER_FILES +=

contains( SYSTEM, helios ) {
    message(System hostname has been defined as helios ...)
    INCLUDEPATH += -I/ikpv2/include -mcmodel=large
    LIBS += -L/ikpv2/lib -lmfile -lm -mcmodel=large -lpthread
} else {
    INCLUDEPATH +=-I/usr/include -mcmodel=large
    LIBS+=   -L/usr/lib -lmfile -lm -mcmodel=large -lpthread
}


 RESOURCES     = src/xs.qrc \
    src/xs.qrc
