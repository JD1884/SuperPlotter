#include "functionpart.h"

FunctionPart::FunctionPart(QObject *parent)
    : QObject{parent}
{

}

int FunctionPart::getErrIndex()
{
    return errIndex;
}

void FunctionPart::setErrIndex(int index)
{
    errIndex = index;
}
