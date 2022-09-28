#ifndef FUNCTIONOFXISY_H
#define FUNCTIONOFXISY_H

#include "function.h"

class FunctionOfXIsY : public Function
{
public:
    explicit FunctionOfXIsY(FunctionCore *myCore, QObject *parent = nullptr);

    double checkForValue (double i);

    void getPlotPoints (double x_start, double x_end, int x_resolution,
                        double y_start, double y_end, int y_resolution,
                        QVector<double> *x_data,
                        QVector<double> *y_data) override;
};

#endif // FUNCTIONOFXISY_H
