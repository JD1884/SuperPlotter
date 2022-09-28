#ifndef NOINPUTFUNCTIONPART_H
#define NOINPUTFUNCTIONPART_H

#include "functionpart.h"

class NoInputFunctionPart : public FunctionPart
{
public:
    explicit NoInputFunctionPart(QObject *parent = nullptr);
};

#endif // NOINPUTFUNCTIONPART_H
