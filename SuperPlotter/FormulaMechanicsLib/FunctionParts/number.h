#ifndef NUMBER_H
#define NUMBER_H

#include "noinputfunctionpart.h"

class Number : public NoInputFunctionPart
{
public:
    explicit Number(double numVal, QObject *parent = nullptr);

    double getVal(double xVal, double yVal = 0.0) override;

private:
    double value;
};

#endif // NUMBER_H
