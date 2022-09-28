#include "basmodisum.h"

BasModiSum::BasModiSum(QObject *parent)
    : TwoInputsFunctionPart{parent}
{

}


double BasModiSum::getVal(double xVal, double yVal)
{
    return left->getVal(xVal, yVal) + right->getVal(xVal, yVal);
}
