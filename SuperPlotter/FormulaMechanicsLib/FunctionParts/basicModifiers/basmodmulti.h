#ifndef BASMODMULTI_H
#define BASMODMULTI_H

#include "../twoinputsfunctionpart.h"

class BasModMulti : public TwoInputsFunctionPart
{
public:
    explicit BasModMulti(QObject *parent = nullptr);

    double getVal(double xVal, double yVal = 0.0) override;
};

#endif // BASMODMULTI_H
