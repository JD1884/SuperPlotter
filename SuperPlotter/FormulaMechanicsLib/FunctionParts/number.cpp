#include "number.h"

Number::Number(double numVal, QObject *parent)
    : NoInputFunctionPart{parent}
{
    value = numVal;
}


double Number::getVal(double xVal, double yVal)
{
    Q_UNUSED(xVal);
    Q_UNUSED(yVal);

    return value;
}
