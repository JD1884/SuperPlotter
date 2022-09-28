#ifndef ONEINPUTDUMMY_H
#define ONEINPUTDUMMY_H

#include "oneinputfunctionpart.h"

class OneInputDummy : public OneInputFunctionPart
{
public:
    explicit OneInputDummy(QObject *parent = nullptr);

    FunctionPart *getFunctionPart();
};

#endif // ONEINPUTDUMMY_H
