#ifndef ONEINPUTFUNCTIONPART_H
#define ONEINPUTFUNCTIONPART_H

#include "functionpart.h"

class OneInputFunctionPart : public FunctionPart
{
public:
    explicit OneInputFunctionPart(QObject *parent = nullptr);

    bool setup(QString);

    double getVal (double xVal, double yVal = 0.0) override;

private:
    bool splitOnFirstSign(QChar sign, QString original, QString* left, QString* right, int* errIndex);
    QString replaceBracketParts(QString formulaString, QList<QString> partsInBrackets);

protected:
    FunctionPart* myFunctionPart;
};

#endif // ONEINPUTFUNCTIONPART_H
