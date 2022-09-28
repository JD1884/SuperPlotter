#include "basmoddev.h"

BasModDev::BasModDev(QObject *parent)
    : TwoInputsFunctionPart{parent}
{

}


double BasModDev::getVal(double xVal, double yVal)
{
    return left->getVal(xVal, yVal) / right->getVal(xVal, yVal);
}
