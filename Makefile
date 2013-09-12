#############################################################################
# Makefile for building: xiaStarter
# Generated by qmake (2.01a) (Qt 4.6.3) on: Thu Sep 12 14:34:18 2013
# Project:  XiaStarter.pro
# Template: app
# Command: /usr/bin/qmake -unix SYSTEM=helios -o Makefile XiaStarter.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I-I/ikpv2/include -I-mcmodel=large -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -L/ikpv2/lib -lmfile -lm -mcmodel=large -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/main.cpp \
		src/xiastarterwindow.cpp \
		src/xiastarter.cpp \
		src/sourceconfdialog.cpp \
		src/about.cpp \
		src/xs_det.cpp \
		src/qcustomplot.cpp \
		src/preferencedialog.cpp \
		src/xs_info.cpp \
		src/dgfconfig.cpp \
		src/psasettings.cpp moc_xiastarterwindow.cpp \
		moc_xiastarter.cpp \
		moc_sourceconfdialog.cpp \
		moc_about.cpp \
		moc_qcustomplot.cpp \
		moc_preferencedialog.cpp \
		moc_dgfconfig.cpp \
		moc_psasettings.cpp \
		qrc_xs.cpp
OBJECTS       = main.o \
		xiastarterwindow.o \
		xiastarter.o \
		sourceconfdialog.o \
		about.o \
		xs_det.o \
		qcustomplot.o \
		preferencedialog.o \
		xs_info.o \
		dgfconfig.o \
		psasettings.o \
		moc_xiastarterwindow.o \
		moc_xiastarter.o \
		moc_sourceconfdialog.o \
		moc_about.o \
		moc_qcustomplot.o \
		moc_preferencedialog.o \
		moc_dgfconfig.o \
		moc_psasettings.o \
		qrc_xs.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		XiaStarter.pro
QMAKE_TARGET  = xiaStarter
DESTDIR       = 
TARGET        = xiaStarter

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_xiastarterwindow.h ui_sourceconfdialog.h ui_about.h ui_preferencedialog.h ui_dgfconfig.h ui_psasettings.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: XiaStarter.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix SYSTEM=helios -o Makefile XiaStarter.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix SYSTEM=helios -o Makefile XiaStarter.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/xiaStarter1.0.0 || $(MKDIR) .tmp/xiaStarter1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/xiaStarter1.0.0/ && $(COPY_FILE) --parents src/xiastarterwindow.h src/xiastarter.h src/sourceconfdialog.h src/about.h src/xs_det.h src/qcustomplot.h src/preferencedialog.h src/xs_info.h src/dgfconfig.h src/psasettings.h .tmp/xiaStarter1.0.0/ && $(COPY_FILE) --parents src/xs.qrc src/xs.qrc .tmp/xiaStarter1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/xiastarterwindow.cpp src/xiastarter.cpp src/sourceconfdialog.cpp src/about.cpp src/xs_det.cpp src/qcustomplot.cpp src/preferencedialog.cpp src/xs_info.cpp src/dgfconfig.cpp src/psasettings.cpp .tmp/xiaStarter1.0.0/ && $(COPY_FILE) --parents src/xiastarterwindow.ui src/sourceconfdialog.ui src/about.ui src/preferencedialog.ui src/dgfconfig.ui src/psasettings.ui .tmp/xiaStarter1.0.0/ && (cd `dirname .tmp/xiaStarter1.0.0` && $(TAR) xiaStarter1.0.0.tar xiaStarter1.0.0 && $(COMPRESS) xiaStarter1.0.0.tar) && $(MOVE) `dirname .tmp/xiaStarter1.0.0`/xiaStarter1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/xiaStarter1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_xiastarterwindow.cpp moc_xiastarter.cpp moc_sourceconfdialog.cpp moc_about.cpp moc_qcustomplot.cpp moc_preferencedialog.cpp moc_dgfconfig.cpp moc_psasettings.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_xiastarterwindow.cpp moc_xiastarter.cpp moc_sourceconfdialog.cpp moc_about.cpp moc_qcustomplot.cpp moc_preferencedialog.cpp moc_dgfconfig.cpp moc_psasettings.cpp
moc_xiastarterwindow.cpp: src/xiastarter.h \
		src/xs_det.h \
		src/preferencedialog.h \
		src/xiastarterwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/xiastarterwindow.h -o moc_xiastarterwindow.cpp

moc_xiastarter.cpp: src/xs_det.h \
		src/xiastarter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/xiastarter.h -o moc_xiastarter.cpp

moc_sourceconfdialog.cpp: src/sourceconfdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/sourceconfdialog.h -o moc_sourceconfdialog.cpp

moc_about.cpp: src/about.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/about.h -o moc_about.cpp

moc_qcustomplot.cpp: src/qcustomplot.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/qcustomplot.h -o moc_qcustomplot.cpp

moc_preferencedialog.cpp: src/xs_det.h \
		src/preferencedialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/preferencedialog.h -o moc_preferencedialog.cpp

moc_dgfconfig.cpp: src/dgfconfig.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/dgfconfig.h -o moc_dgfconfig.cpp

moc_psasettings.cpp: src/psasettings.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/psasettings.h -o moc_psasettings.cpp

compiler_rcc_make_all: qrc_xs.cpp qrc_xs.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_xs.cpp qrc_xs.cpp
qrc_xs.cpp: src/xs.qrc \
		img/scaler.png \
		img/readymca.png \
		img/dgfconfig.png \
		img/rates.png \
		img/start.png \
		img/booted.png \
		img/running.png \
		img/editsourceconf.png
	/usr/bin/rcc -name xs src/xs.qrc -o qrc_xs.cpp

qrc_xs.cpp: src/xs.qrc \
		img/scaler.png \
		img/readymca.png \
		img/dgfconfig.png \
		img/rates.png \
		img/start.png \
		img/booted.png \
		img/running.png \
		img/editsourceconf.png
	/usr/bin/rcc -name xs src/xs.qrc -o qrc_xs.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_xiastarterwindow.h ui_sourceconfdialog.h ui_about.h ui_preferencedialog.h ui_dgfconfig.h ui_psasettings.h
compiler_uic_clean:
	-$(DEL_FILE) ui_xiastarterwindow.h ui_sourceconfdialog.h ui_about.h ui_preferencedialog.h ui_dgfconfig.h ui_psasettings.h
ui_xiastarterwindow.h: src/xiastarterwindow.ui
	/usr/bin/uic-qt4 src/xiastarterwindow.ui -o ui_xiastarterwindow.h

ui_sourceconfdialog.h: src/sourceconfdialog.ui
	/usr/bin/uic-qt4 src/sourceconfdialog.ui -o ui_sourceconfdialog.h

ui_about.h: src/about.ui
	/usr/bin/uic-qt4 src/about.ui -o ui_about.h

ui_preferencedialog.h: src/preferencedialog.ui
	/usr/bin/uic-qt4 src/preferencedialog.ui -o ui_preferencedialog.h

ui_dgfconfig.h: src/dgfconfig.ui
	/usr/bin/uic-qt4 src/dgfconfig.ui -o ui_dgfconfig.h

ui_psasettings.h: src/psasettings.ui
	/usr/bin/uic-qt4 src/psasettings.ui -o ui_psasettings.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: src/main.cpp src/xiastarterwindow.h \
		src/xiastarter.h \
		src/xs_det.h \
		src/preferencedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

xiastarterwindow.o: src/xiastarterwindow.cpp src/xiastarterwindow.h \
		src/xiastarter.h \
		src/xs_det.h \
		src/preferencedialog.h \
		ui_xiastarterwindow.h \
		src/sourceconfdialog.h \
		src/about.h \
		/usr/local/include/mfile.h \
		src/dgfconfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o xiastarterwindow.o src/xiastarterwindow.cpp

xiastarter.o: src/xiastarter.cpp src/xiastarter.h \
		src/xs_det.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o xiastarter.o src/xiastarter.cpp

sourceconfdialog.o: src/sourceconfdialog.cpp src/sourceconfdialog.h \
		ui_sourceconfdialog.h \
		src/xiastarterwindow.h \
		src/xiastarter.h \
		src/xs_det.h \
		src/preferencedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sourceconfdialog.o src/sourceconfdialog.cpp

about.o: src/about.cpp src/about.h \
		ui_about.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o about.o src/about.cpp

xs_det.o: src/xs_det.cpp src/xs_det.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o xs_det.o src/xs_det.cpp

qcustomplot.o: src/qcustomplot.cpp src/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qcustomplot.o src/qcustomplot.cpp

preferencedialog.o: src/preferencedialog.cpp src/preferencedialog.h \
		src/xs_det.h \
		ui_preferencedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o preferencedialog.o src/preferencedialog.cpp

xs_info.o: src/xs_info.cpp src/xs_info.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o xs_info.o src/xs_info.cpp

dgfconfig.o: src/dgfconfig.cpp src/dgfconfig.h \
		ui_dgfconfig.h \
		src/psasettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dgfconfig.o src/dgfconfig.cpp

psasettings.o: src/psasettings.cpp src/psasettings.h \
		ui_psasettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o psasettings.o src/psasettings.cpp

moc_xiastarterwindow.o: moc_xiastarterwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_xiastarterwindow.o moc_xiastarterwindow.cpp

moc_xiastarter.o: moc_xiastarter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_xiastarter.o moc_xiastarter.cpp

moc_sourceconfdialog.o: moc_sourceconfdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_sourceconfdialog.o moc_sourceconfdialog.cpp

moc_about.o: moc_about.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_about.o moc_about.cpp

moc_qcustomplot.o: moc_qcustomplot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qcustomplot.o moc_qcustomplot.cpp

moc_preferencedialog.o: moc_preferencedialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_preferencedialog.o moc_preferencedialog.cpp

moc_dgfconfig.o: moc_dgfconfig.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dgfconfig.o moc_dgfconfig.cpp

moc_psasettings.o: moc_psasettings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_psasettings.o moc_psasettings.cpp

qrc_xs.o: qrc_xs.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_xs.o qrc_xs.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

