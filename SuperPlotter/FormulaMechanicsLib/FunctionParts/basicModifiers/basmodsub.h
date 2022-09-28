#ifndef BASMODSUB_H
#define BASMODSUB_H

#include "../twoinputsfunctionpart.h"

class BasModSub : public TwoInputsFunctionPart
{
public:
    explicit BasModSub(QObject *parent = nullptr);

    double getVal(double xVal, double yVal = 0.0) override;
};

#endif // BASMODSUB_H
