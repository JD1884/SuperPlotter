#include "function.h"

Function::Function(FunctionCore *myCore, QObject *parent)
    : QObject{parent}, myCore(myCore)
{

}
