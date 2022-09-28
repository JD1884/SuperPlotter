#ifndef VARIABLE_H
#define VARIABLE_H

#include "noinputfunctionpart.h"

class Variable : public NoInputFunctionPart
{
public:
    explicit Variable(bool xOrY, QObject *parent = nullptr);

    double getVal(double xVal, double yVal = 0.0) override;

private:
    bool xOrY;  // false = x ; true = y;
};

#endif // VARIABLE_H
