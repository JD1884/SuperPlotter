#ifndef FUNCTIONOFXANDYISZERO_H
#define FUNCTIONOFXANDYISZERO_H

#include "function.h"

class FunctionOfXAndYIsZero : public Function
{
public:
    explicit FunctionOfXAndYIsZero(FunctionCore *myCore, QObject *parent = nullptr);

    double checkVal (double x, double y);

    void getPlotPoints (double x_start, double x_end, int x_resolution,
                        double y_start, double y_end, int y_resolution,
                        QVector<double> *x_data,
                        QVector<double> *y_data) override;


private:
    double disSquare (double x1, double y1,
                      double x2, double y2);
};

#endif // FUNCTIONOFXANDYISZERO_H
