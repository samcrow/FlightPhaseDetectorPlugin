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

PRIVATENAMESPACE = SCFlightPhaseDetector
DEFINES += PRIVATENAMESPACE=$$PRIVATENAMESPACE


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

        # libpng
        LIBS += -L/opt/local/lib/libpng-static -lpng

        # Boost
        INCLUDEPATH += /opt/local/include

        # Build for multiple architectures.
        # The following line is only needed to build universal on PPC architectures.
        # QMAKE_MAC_SDK=/Developer/SDKs/MacOSX10.4u.sdk
        # The following line defines for which architectures we build.
        CONFIG += x86 # ppc
}

SOURCES += \ 
    mvc/models/airdatamodelxplane.cpp \
    plugin_interface/plugin.cpp \
    flightphasedetectorplugin.cpp \
    plugin_main.cpp

HEADERS += \ 
    mvc/models/airdatamodel.h \
    mvc/models/airdatamodelxplane.h \
    plugin_interface/plugin.h \
    flightphasedetectorplugin.h \
    mvc/models/flightphasemodel.h \
    fsm/fsmdefs.h \
    fsm/events.h \
    fsm/outer_states.h


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/PPL/lib$$PRIVATENAMESPACE/release/ -lppl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/PPL/lib$$PRIVATENAMESPACE/debug/ -lppl
else:unix: LIBS += -L$$PWD/PPL/lib$$PRIVATENAMESPACE/ -lppl

INCLUDEPATH += $$PWD/PPL/src
DEPENDPATH += $$PWD/PPL/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/PPL/lib$$PRIVATENAMESPACE/release/libppl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/PPL/lib$$PRIVATENAMESPACE/debug/libppl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/PPL/lib$$PRIVATENAMESPACE/release/ppl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/PPL/lib$$PRIVATENAMESPACE/debug/ppl.lib
else:unix: PRE_TARGETDEPS += $$PWD/PPL/lib$$PRIVATENAMESPACE/libppl.a

