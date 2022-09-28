#include "functionofxisy.h"

FunctionOfXIsY::FunctionOfXIsY(FunctionCore *myCore, QObject *parent)
    : Function{myCore, parent}
{

}

double FunctionOfXIsY::checkForValue(double i)
{
    return myCore->getVal(i);
}


void FunctionOfXIsY::getPlotPoints (double x_start, double x_end, int x_resolution,
                                    double y_start, double y_end, int y_resolution,
                                    QVector<double> *x_data,
                                    QVector<double> *y_data)
{
    Q_UNUSED (y_start);
    Q_UNUSED (y_end);
    Q_UNUSED (y_resolution);

    x_data->clear();
    y_data->clear();

    double x_stepSize = (x_end - x_start) / x_resolution;

    for (int i = 0; i < x_resolution; ++i)
    {
        double x_value = x_start + i * x_stepSize;

        x_data->push_back(x_value);
        y_data->push_back(checkForValue(x_value));
    }
}
