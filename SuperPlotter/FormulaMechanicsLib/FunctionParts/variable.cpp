#include "variable.h"

Variable::Variable(bool xOrY, QObject *parent)
    : NoInputFunctionPart{parent}, xOrY(xOrY)
{

}


double Variable::getVal(double xVal, double yVal)
{
    if (xOrY)
        return yVal;

    return xVal;
}
