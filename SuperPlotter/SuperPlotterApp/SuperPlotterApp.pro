QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    InputWidget/abstractinteractionwidget.cpp \
    InputWidget/constantmanipulatorwidget.cpp \
    InputWidget/functioninputwidget.cpp \
    InputWidget/inputwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    plotterwidget.cpp \
    qcustomplot.cpp

HEADERS += \
    InputWidget/abstractinteractionwidget.h \
    InputWidget/constantmanipulatorwidget.h \
    InputWidget/functioninputwidget.h \
    InputWidget/inputwidget.h \
    mainwindow.h \
    plotterwidget.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
