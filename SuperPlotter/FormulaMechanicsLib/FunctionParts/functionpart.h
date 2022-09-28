#ifndef FUNCTIONPART_H
#define FUNCTIONPART_H

#include <QObject>

class FunctionPart : public QObject
{
    Q_OBJECT
public:
    explicit FunctionPart(QObject *parent = nullptr);

    int getErrIndex();

    virtual double getVal(double xVal, double yVal = 0.0) = 0;

protected:
    void setErrIndex(int index);

private:
    int errIndex;
};

#endif // FUNCTIONPART_H
