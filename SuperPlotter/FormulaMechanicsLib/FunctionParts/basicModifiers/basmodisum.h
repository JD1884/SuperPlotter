#ifndef BASMODISUM_H
#define BASMODISUM_H

#include "../twoinputsfunctionpart.h"

class BasModiSum : public TwoInputsFunctionPart
{
public:
    explicit BasModiSum(QObject *parent = nullptr);

    double getVal(double xVal, double yVal = 0.0) override;
};

#endif // BASMODISUM_H
