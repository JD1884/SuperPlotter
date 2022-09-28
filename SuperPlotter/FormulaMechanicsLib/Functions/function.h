#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "../FunctionParts/functioncore.h"

class Function : public QObject
{
    Q_OBJECT
public:
    explicit Function(FunctionCore *myCore, QObject *parent = nullptr);

    virtual void getPlotPoints (double x_start, double x_end, int x_resolution,
                                double y_start, double y_end, int y_resolution,
                                QVector<double> *x_data,
                                QVector<double> *y_data) = 0;

protected:
    FunctionCore *myCore;
};

#endif // FUNCTION_H
