#include "oneinputdummy.h"

OneInputDummy::OneInputDummy(QObject *parent)
    : OneInputFunctionPart{parent}
{

}


FunctionPart *OneInputDummy::getFunctionPart()
{
    return myFunctionPart;
}
