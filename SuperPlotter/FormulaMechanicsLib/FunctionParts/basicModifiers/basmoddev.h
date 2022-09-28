#ifndef BASMODDEV_H
#define BASMODDEV_H

#include "../twoinputsfunctionpart.h"

class BasModDev : public TwoInputsFunctionPart
{
public:
    explicit BasModDev(QObject *parent = nullptr);

    double getVal(double xVal, double yVal = 0.0) override;
};

#endif // BASMODDEV_H
