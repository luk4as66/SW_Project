#############################################################################
# Makefile for building: dist/Release/GNU-Linux-x86/SW_Project
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue Sep 11 02:34:33 2012
# Project:  nbproject/qt-Release.pro
# Template: app
# Command: /home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake VPATH=. -o qttmp-Release.mk nbproject/qt-Release.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/default -Inbproject -I../../QtSDK/Desktop/Qt/4.8.1/gcc/include/QtCore -I../../QtSDK/Desktop/Qt/4.8.1/gcc/include/QtGui -I../../QtSDK/Desktop/Qt/4.8.1/gcc/include -I/usr/include/bluetooth -I. -Inbproject -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/lib -lbluetooth -lQtGui -L/home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/lib -L/usr/X11R6/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake
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

OBJECTS_DIR   = build/Release/GNU-Linux-x86/

####### Files

SOURCES       = MainWindow.cpp \
		connectPanelClass.cpp \
		main.cpp \
		SearchDevices.cpp moc_MainWindow.cpp
OBJECTS       = build/Release/GNU-Linux-x86/MainWindow.o \
		build/Release/GNU-Linux-x86/connectPanelClass.o \
		build/Release/GNU-Linux-x86/main.o \
		build/Release/GNU-Linux-x86/SearchDevices.o \
		build/Release/GNU-Linux-x86/moc_MainWindow.o
DIST          = ../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/link_pkgconfig.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Release.pro
QMAKE_TARGET  = SW_Project
DESTDIR       = dist/Release/GNU-Linux-x86/
TARGET        = dist/Release/GNU-Linux-x86/SW_Project

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

all: qttmp-Release.mk $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Release/GNU-Linux-x86/ || $(MKDIR) dist/Release/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qttmp-Release.mk: nbproject/qt-Release.pro  ../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/link_pkgconfig.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		/home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl \
		/home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl
	$(QMAKE) VPATH=. -o qttmp-Release.mk nbproject/qt-Release.pro
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/link_pkgconfig.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf:
../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf:
/home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl:
/home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Release.mk nbproject/qt-Release.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Release/GNU-Linux-x86/SW_Project1.0.0 || $(MKDIR) build/Release/GNU-Linux-x86/SW_Project1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Release/GNU-Linux-x86/SW_Project1.0.0/ && $(COPY_FILE) --parents connectPanelClass.h MainWindow.h SearchDevices.h build/Release/GNU-Linux-x86/SW_Project1.0.0/ && $(COPY_FILE) --parents MainWindow.cpp connectPanelClass.cpp main.cpp SearchDevices.cpp build/Release/GNU-Linux-x86/SW_Project1.0.0/ && (cd `dirname build/Release/GNU-Linux-x86/SW_Project1.0.0` && $(TAR) SW_Project1.0.0.tar SW_Project1.0.0 && $(COMPRESS) SW_Project1.0.0.tar) && $(MOVE) `dirname build/Release/GNU-Linux-x86/SW_Project1.0.0`/SW_Project1.0.0.tar.gz . && $(DEL_FILE) -r build/Release/GNU-Linux-x86/SW_Project1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Release.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp
moc_MainWindow.cpp: connectPanelClass.h \
		SearchDevices.h \
		MainWindow.h
	/home/pablo/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) MainWindow.h -o moc_MainWindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

build/Release/GNU-Linux-x86/MainWindow.o: MainWindow.cpp MainWindow.h \
		connectPanelClass.h \
		SearchDevices.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/MainWindow.o MainWindow.cpp

build/Release/GNU-Linux-x86/connectPanelClass.o: connectPanelClass.cpp connectPanelClass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/connectPanelClass.o connectPanelClass.cpp

build/Release/GNU-Linux-x86/main.o: main.cpp MainWindow.h \
		connectPanelClass.h \
		SearchDevices.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/main.o main.cpp

build/Release/GNU-Linux-x86/SearchDevices.o: SearchDevices.cpp SearchDevices.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/SearchDevices.o SearchDevices.cpp

build/Release/GNU-Linux-x86/moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/moc_MainWindow.o moc_MainWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

