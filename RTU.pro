# Shared library without any Qt functionality
TEMPLATE = lib
QT -= gui core

CONFIG += warn_on plugin debug c++11
CONFIG -= thread exceptions qt rtti

VERSION = 1.0.0

INCLUDEPATH += ./SDK/CHeaders/XPLM
INCLUDEPATH += ./SDK/CHeaders/Wrappers
INCLUDEPATH += ./SDK/CHeaders/Widgets

# Defined to use X-Plane SDK 2.0 capabilities - no backward compatibility before 9.0
DEFINES += XPLM200 XPLM210

DEFINES += PRIVATENAMESPACE=SCRTUPPL


win32 {
        DEFINES += APL=0 IBM=1 LIN=0
        LIBS += -L../SDK/Libraries/Win
        LIBS += -lXPLM -lXPWidgets
        TARGET = win.xpl
}

unix:!macx {
        DEFINES += APL=0 IBM=0 LIN=1
        TARGET = lin.xpl
        # WARNING! This requires the latest version of the X-SDK !!!!
        QMAKE_CXXFLAGS += -fvisibility=hidden
}

macx {
        DEFINES += APL=1 IBM=0 LIN=0
        TARGET = mac.xpl
        QMAKE_LFLAGS += -flat_namespace -undefined suppress

        # GLEW
        INCLUDEPATH += /opt/local/include
        LIBS += -L/opt/local/lib/libGLEW-static -lGLEW

        # Freetype
        INCLUDEPATH += ./PPL/include
        INCLUDEPATH += ./PPL/include/freetype2
        LIBS += -L/opt/local/lib/libfreetype-static -lfreetype

       # libpng
       LIBS += -L/opt/local/lib/libpng-static -lpng

        # Build for multiple architectures.
        # The following line is only needed to build universal on PPC architectures.
        # QMAKE_MAC_SDK=/Developer/SDKs/MacOSX10.4u.sdk
        # The following line defines for which architectures we build.
        CONFIG += x86 # ppc
}

SOURCES += \
    plugin_main.cpp \
    plugin_interface/plugin.cpp \
    plugin_interface/testplugin.cpp \
    mvc/data/frequency.cpp \
    rtuplugin.cpp \
    mvc/models/tuningmodel.cpp \
    mvc/models/tuningmodelxplane.cpp \
    mvc/models/frequencydatarefpair.cpp \
    mvc/models/adffrequencydatarefpair.cpp \
    mvc/controllers/rtucontroller.cpp \
    mvc/connectors/rtuxplanecommandconnector.cpp \
    mvc/controllers/rtupage.cpp \
    mvc/controllers/rtuatcpage.cpp \
    mvc/views/rtuview.cpp \
    mvc/views/rtumetrics.cpp \
    mvc/views/rtu/rtuatcpageview.cpp \
    mvc/views/rtuviewcomponent.cpp \
    mvc/controllers/rtuadfpage.cpp \
    mvc/views/rtu/rtuadfpageview.cpp \
    mvc/controllers/rtuprimarypage.cpp \
    mvc/views/rtu/rtuprimarypageview.cpp \
    mvc/models/frequencyowneddatapair.cpp \
    mvc/controllers/rtufrequencypaircontroller.cpp

HEADERS += \
    plugin_interface/plugin.h \
    plugin_interface/testplugin.h \
    mvc/data/frequency.h \
    rtuplugin.h \
    mvc/models/tuningmodel.h \
    mvc/models/tuningmodelxplane.h \
    mvc/models/frequencydatarefpair.h \
    mvc/models/adffrequencydatarefpair.h \
    mvc/controllers/rtucontroller.h \
    mvc/connectors/rtuxplanecommandconnector.h \
    mvc/controllers/rtupage.h \
    mvc/controllers/rtuatcpage.h \
    mvc/views/rtuview.h \
    mvc/views/rtumetrics.h \
    mvc/views/rtu/rtuatcpageview.h \
    mvc/views/rtuviewcomponent.h \
    mvc/controllers/rtuadfpage.h \
    mvc/views/rtu/rtuadfpageview.h \
    mvc/controllers/rtuprimarypage.h \
    mvc/views/rtu/rtuprimarypageview.h \
    mvc/models/frequencyowneddatapair.h \
    mvc/controllers/rtufrequencypaircontroller.h


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/PPL/libSCRTUPPL/release/ -lppl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/PPL/libSCRTUPPL/debug/ -lppl
else:unix: LIBS += -L$$PWD/PPL/libSCRTUPPL/ -lppl

INCLUDEPATH += $$PWD/PPL/src
DEPENDPATH += $$PWD/PPL/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/PPL/libSCRTUPPL/release/libppl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/PPL/libSCRTUPPL/debug/libppl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/PPL/libSCRTUPPL/release/ppl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/PPL/libSCRTUPPL/debug/ppl.lib
else:unix: PRE_TARGETDEPS += $$PWD/PPL/libSCRTUPPL/libppl.a

