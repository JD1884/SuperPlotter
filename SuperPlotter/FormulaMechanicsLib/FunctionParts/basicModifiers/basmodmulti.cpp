#include "basmodmulti.h"

BasModMulti::BasModMulti(QObject *parent)
    : TwoInputsFunctionPart{parent}
{

}


double BasModMulti::getVal(double xVal, double yVal)
{
    return left->getVal(xVal, yVal) * right->getVal(xVal, yVal);
}
