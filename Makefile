#############################################################################
# Makefile for building: bin/xiaStarter
# Generated by qmake (2.01a) (Qt 4.6.2) on: Mon Jan 22 12:33:43 2018
# Project:  XiaStarter.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile XiaStarter.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I-I/usr/include -I-mcmodel=large -Imoc -Iui
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -L/usr/lib -lmfile -lm -mcmodel=large -lQtGui -lQtCore -lpthread 
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

OBJECTS_DIR   = obj/

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
		src/psasettings.cpp moc/moc_xiastarterwindow.cpp \
		moc/moc_xiastarter.cpp \
		moc/moc_sourceconfdialog.cpp \
		moc/moc_about.cpp \
		moc/moc_qcustomplot.cpp \
		moc/moc_preferencedialog.cpp \
		moc/moc_dgfconfig.cpp \
		moc/moc_psasettings.cpp \
		qrc_xs.cpp
OBJECTS       = obj/main.o \
		obj/xiastarterwindow.o \
		obj/xiastarter.o \
		obj/sourceconfdialog.o \
		obj/about.o \
		obj/xs_det.o \
		obj/qcustomplot.o \
		obj/preferencedialog.o \
		obj/xs_info.o \
		obj/dgfconfig.o \
		obj/psasettings.o \
		obj/moc_xiastarterwindow.o \
		obj/moc_xiastarter.o \
		obj/moc_sourceconfdialog.o \
		obj/moc_about.o \
		obj/moc_qcustomplot.o \
		obj/moc_preferencedialog.o \
		obj/moc_dgfconfig.o \
		obj/moc_psasettings.o \
		obj/qrc_xs.o
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
		XiaStarter.pro
QMAKE_TARGET  = xiaStarter
DESTDIR       = bin/
TARGET        = bin/xiaStarter

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

$(TARGET): ui/ui_xiastarterwindow.h ui/ui_sourceconfdialog.h ui/ui_about.h ui/ui_preferencedialog.h ui/ui_dgfconfig.h ui/ui_psasettings.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
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
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile XiaStarter.pro
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
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile XiaStarter.pro

dist: 
	@$(CHK_DIR_EXISTS) obj/xiaStarter1.0.0 || $(MKDIR) obj/xiaStarter1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) obj/xiaStarter1.0.0/ && $(COPY_FILE) --parents src/xiastarterwindow.h src/xiastarter.h src/sourceconfdialog.h src/about.h src/xs_det.h src/qcustomplot.h src/preferencedialog.h src/xs_info.h src/dgfconfig.h src/psasettings.h obj/xiaStarter1.0.0/ && $(COPY_FILE) --parents src/xs.qrc src/xs.qrc obj/xiaStarter1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/xiastarterwindow.cpp src/xiastarter.cpp src/sourceconfdialog.cpp src/about.cpp src/xs_det.cpp src/qcustomplot.cpp src/preferencedialog.cpp src/xs_info.cpp src/dgfconfig.cpp src/psasettings.cpp obj/xiaStarter1.0.0/ && $(COPY_FILE) --parents src/xiastarterwindow.ui src/sourceconfdialog.ui src/about.ui src/preferencedialog.ui src/dgfconfig.ui src/psasettings.ui obj/xiaStarter1.0.0/ && (cd `dirname obj/xiaStarter1.0.0` && $(TAR) xiaStarter1.0.0.tar xiaStarter1.0.0 && $(COMPRESS) xiaStarter1.0.0.tar) && $(MOVE) `dirname obj/xiaStarter1.0.0`/xiaStarter1.0.0.tar.gz . && $(DEL_FILE) -r obj/xiaStarter1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc/moc_xiastarterwindow.cpp moc/moc_xiastarter.cpp moc/moc_sourceconfdialog.cpp moc/moc_about.cpp moc/moc_qcustomplot.cpp moc/moc_preferencedialog.cpp moc/moc_dgfconfig.cpp moc/moc_psasettings.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_xiastarterwindow.cpp moc/moc_xiastarter.cpp moc/moc_sourceconfdialog.cpp moc/moc_about.cpp moc/moc_qcustomplot.cpp moc/moc_preferencedialog.cpp moc/moc_dgfconfig.cpp moc/moc_psasettings.cpp
moc/moc_xiastarterwindow.cpp: src/xiastarter.h \
		src/xs_det.h \
		src/preferencedialog.h \
		src/xiastarterwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/xiastarterwindow.h -o moc/moc_xiastarterwindow.cpp

moc/moc_xiastarter.cpp: src/xs_det.h \
		src/xiastarter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/xiastarter.h -o moc/moc_xiastarter.cpp

moc/moc_sourceconfdialog.cpp: src/sourceconfdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/sourceconfdialog.h -o moc/moc_sourceconfdialog.cpp

moc/moc_about.cpp: src/about.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/about.h -o moc/moc_about.cpp

moc/moc_qcustomplot.cpp: src/qcustomplot.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/qcustomplot.h -o moc/moc_qcustomplot.cpp

moc/moc_preferencedialog.cpp: src/xs_det.h \
		src/preferencedialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/preferencedialog.h -o moc/moc_preferencedialog.cpp

moc/moc_dgfconfig.cpp: src/dgfconfig.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/dgfconfig.h -o moc/moc_dgfconfig.cpp

moc/moc_psasettings.cpp: src/psasettings.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/psasettings.h -o moc/moc_psasettings.cpp

compiler_rcc_make_all: qrc_xs.cpp qrc_xs.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_xs.cpp qrc_xs.cpp
qrc_xs.cpp: src/xs.qrc
	/usr/bin/rcc -name xs src/xs.qrc -o qrc_xs.cpp

qrc_xs.cpp: src/xs.qrc
	/usr/bin/rcc -name xs src/xs.qrc -o qrc_xs.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui/ui_xiastarterwindow.h ui/ui_sourceconfdialog.h ui/ui_about.h ui/ui_preferencedialog.h ui/ui_dgfconfig.h ui/ui_psasettings.h
compiler_uic_clean:
	-$(DEL_FILE) ui/ui_xiastarterwindow.h ui/ui_sourceconfdialog.h ui/ui_about.h ui/ui_preferencedialog.h ui/ui_dgfconfig.h ui/ui_psasettings.h
ui/ui_xiastarterwindow.h: src/xiastarterwindow.ui \
		src/qcustomplot.h
	/usr/bin/uic-qt4 src/xiastarterwindow.ui -o ui/ui_xiastarterwindow.h

ui/ui_sourceconfdialog.h: src/sourceconfdialog.ui
	/usr/bin/uic-qt4 src/sourceconfdialog.ui -o ui/ui_sourceconfdialog.h

ui/ui_about.h: src/about.ui
	/usr/bin/uic-qt4 src/about.ui -o ui/ui_about.h

ui/ui_preferencedialog.h: src/preferencedialog.ui
	/usr/bin/uic-qt4 src/preferencedialog.ui -o ui/ui_preferencedialog.h

ui/ui_dgfconfig.h: src/dgfconfig.ui
	/usr/bin/uic-qt4 src/dgfconfig.ui -o ui/ui_dgfconfig.h

ui/ui_psasettings.h: src/psasettings.ui
	/usr/bin/uic-qt4 src/psasettings.ui -o ui/ui_psasettings.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

obj/main.o: src/main.cpp src/xiastarterwindow.h \
		src/xiastarter.h \
		src/xs_det.h \
		src/preferencedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o src/main.cpp

obj/xiastarterwindow.o: src/xiastarterwindow.cpp src/xiastarterwindow.h \
		src/xiastarter.h \
		src/xs_det.h \
		src/preferencedialog.h \
		ui/ui_xiastarterwindow.h \
		src/qcustomplot.h \
		src/sourceconfdialog.h \
		src/about.h \
		src/dgfconfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/xiastarterwindow.o src/xiastarterwindow.cpp

obj/xiastarter.o: src/xiastarter.cpp src/xiastarter.h \
		src/xs_det.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/xiastarter.o src/xiastarter.cpp

obj/sourceconfdialog.o: src/sourceconfdialog.cpp src/sourceconfdialog.h \
		ui/ui_sourceconfdialog.h \
		src/xiastarterwindow.h \
		src/xiastarter.h \
		src/xs_det.h \
		src/preferencedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/sourceconfdialog.o src/sourceconfdialog.cpp

obj/about.o: src/about.cpp src/about.h \
		ui/ui_about.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/about.o src/about.cpp

obj/xs_det.o: src/xs_det.cpp src/xs_det.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/xs_det.o src/xs_det.cpp

obj/qcustomplot.o: src/qcustomplot.cpp src/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qcustomplot.o src/qcustomplot.cpp

obj/preferencedialog.o: src/preferencedialog.cpp src/preferencedialog.h \
		src/xs_det.h \
		ui/ui_preferencedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/preferencedialog.o src/preferencedialog.cpp

obj/xs_info.o: src/xs_info.cpp src/xs_info.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/xs_info.o src/xs_info.cpp

obj/dgfconfig.o: src/dgfconfig.cpp src/dgfconfig.h \
		ui/ui_dgfconfig.h \
		src/psasettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/dgfconfig.o src/dgfconfig.cpp

obj/psasettings.o: src/psasettings.cpp src/psasettings.h \
		ui/ui_psasettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/psasettings.o src/psasettings.cpp

obj/moc_xiastarterwindow.o: moc/moc_xiastarterwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_xiastarterwindow.o moc/moc_xiastarterwindow.cpp

obj/moc_xiastarter.o: moc/moc_xiastarter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_xiastarter.o moc/moc_xiastarter.cpp

obj/moc_sourceconfdialog.o: moc/moc_sourceconfdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_sourceconfdialog.o moc/moc_sourceconfdialog.cpp

obj/moc_about.o: moc/moc_about.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_about.o moc/moc_about.cpp

obj/moc_qcustomplot.o: moc/moc_qcustomplot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_qcustomplot.o moc/moc_qcustomplot.cpp

obj/moc_preferencedialog.o: moc/moc_preferencedialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_preferencedialog.o moc/moc_preferencedialog.cpp

obj/moc_dgfconfig.o: moc/moc_dgfconfig.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_dgfconfig.o moc/moc_dgfconfig.cpp

obj/moc_psasettings.o: moc/moc_psasettings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_psasettings.o moc/moc_psasettings.cpp

obj/qrc_xs.o: qrc_xs.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qrc_xs.o qrc_xs.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

