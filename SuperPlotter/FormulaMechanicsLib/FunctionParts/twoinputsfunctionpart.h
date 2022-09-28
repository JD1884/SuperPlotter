#ifndef TWOINPUTSFUNCTIONPART_H
#define TWOINPUTSFUNCTIONPART_H

#include "oneinputfunctionpart.h"

class TwoInputsFunctionPart : public FunctionPart
{
public:
    explicit TwoInputsFunctionPart(QObject *parent = nullptr);

    bool setup (QString left, QString right);

protected:
    OneInputFunctionPart *left;
    OneInputFunctionPart *right;
};

#endif // TWOINPUTSFUNCTIONPART_H
