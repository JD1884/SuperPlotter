QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FunctionParts/basicModifiers/basmoddev.cpp \
    FunctionParts/basicModifiers/basmodisum.cpp \
    FunctionParts/basicModifiers/basmodmulti.cpp \
    FunctionParts/basicModifiers/basmodsub.cpp \
    FunctionParts/functioncore.cpp \
    FunctionParts/functionpart.cpp \
    FunctionParts/noinputfunctionpart.cpp \
    FunctionParts/number.cpp \
    FunctionParts/oneinputdummy.cpp \
    FunctionParts/oneinputfunctionpart.cpp \
    FunctionParts/twoinputsfunctionpart.cpp \
    FunctionParts/variable.cpp \
    Functions/function.cpp \
    Functions/functionofxandyiszero.cpp \
    Functions/functionofxisy.cpp \
    formulacreator.cpp \
    formulamechanicslib.cpp

HEADERS += \
    FunctionParts/basicModifiers/basmoddev.h \
    FunctionParts/basicModifiers/basmodisum.h \
    FunctionParts/basicModifiers/basmodmulti.h \
    FunctionParts/basicModifiers/basmodsub.h \
    FunctionParts/functioncore.h \
    FunctionParts/functionpart.h \
    FunctionParts/noinputfunctionpart.h \
    FunctionParts/number.h \
    FunctionParts/oneinputdummy.h \
    FunctionParts/oneinputfunctionpart.h \
    FunctionParts/twoinputsfunctionpart.h \
    FunctionParts/variable.h \
    Functions/function.h \
    Functions/functionofxandyiszero.h \
    Functions/functionofxisy.h \
    formulacreator.h \
    formulamechanicslib.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
