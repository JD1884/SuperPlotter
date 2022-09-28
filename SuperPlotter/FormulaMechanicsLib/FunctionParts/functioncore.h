#ifndef FUNCTIONCORE_H
#define FUNCTIONCORE_H

#include "oneinputfunctionpart.h"

class FunctionCore : public OneInputFunctionPart
{
public:
    explicit FunctionCore(QObject *parent = nullptr);
};

#endif // FUNCTIONCORE_H
