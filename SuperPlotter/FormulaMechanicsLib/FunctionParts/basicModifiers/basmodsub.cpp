#include "basmodsub.h"

BasModSub::BasModSub(QObject *parent)
    : TwoInputsFunctionPart{parent}
{

}


double BasModSub::getVal(double xVal, double yVal)
{
    return left->getVal(xVal, yVal) - right->getVal(xVal, yVal);
}
