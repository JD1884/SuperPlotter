QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_formulamechanics.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../FormulaMechanicsLib/release/ -lFormulaMechanicsLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../FormulaMechanicsLib/debug/ -lFormulaMechanicsLib
else:unix: LIBS += -L$$OUT_PWD/../FormulaMechanicsLib/ -lFormulaMechanicsLib

INCLUDEPATH += $$PWD/../FormulaMechanicsLib
DEPENDPATH += $$PWD/../FormulaMechanicsLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FormulaMechanicsLib/release/libFormulaMechanicsLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FormulaMechanicsLib/debug/libFormulaMechanicsLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FormulaMechanicsLib/release/FormulaMechanicsLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FormulaMechanicsLib/debug/FormulaMechanicsLib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../FormulaMechanicsLib/libFormulaMechanicsLib.a
