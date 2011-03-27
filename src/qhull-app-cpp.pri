# -------------------------------------------------
# qhull-app-cpp.pri -- Qt include project for static CPP qhull applications using Qt
# -------------------------------------------------

DESTDIR = ../../bin
TEMPLATE = app
CONFIG += console warn_on
CONFIG -= rtti
LIBS += -L../../lib
build_pass:CONFIG(debug, debug|release){
   LIBS += -lqhullcpp-d
   LIBS += -lqhullstatic-pd  # Must be last, otherwise qh_fprintf,etc. are loaded from here instead of qhullcpp-d.lib
   OBJECTS_DIR = Debug
}else:build_pass:CONFIG(release, debug|release){
   LIBS += -lqhullcpp
   LIBS += -lqhullstatic-p  # Must be last, otherwise qh_fprintf,etc. are loaded from here instead of qhullcpp.lib
   OBJECTS_DIR = Release
}
win32-msvc* : QMAKE_LFLAGS += /INCREMENTAL:NO

DEFINES += qh_QHpointer # libqhull/user.h

include(qhull-warn.pri)

INCLUDEPATH += ../libqhullcpp
INCLUDEPATH += ../../src # e.g., "road/RoadError.h"
