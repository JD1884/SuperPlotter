#include "functionofxandyiszero.h"

FunctionOfXAndYIsZero::FunctionOfXAndYIsZero(FunctionCore *myCore, QObject *parent)
    : Function{myCore, parent}
{

}


double FunctionOfXAndYIsZero::checkVal (double x, double y)
{
    return myCore->getVal(x, y);
}


void FunctionOfXAndYIsZero::getPlotPoints (double x_start, double x_end, int x_resolution,
                                           double y_start, double y_end, int y_resolution,
                                           QVector<double> *x_data,
                                           QVector<double> *y_data)
{
    x_data->clear();
    y_data->clear();

    QList<double> x_data_temp;
    QList<double> y_data_temp;


    double x_stepSize = (x_end - x_start) / x_resolution;
    double y_stepSize = (y_end - y_start) / y_resolution;


    for (int x_i = 0; x_i < x_resolution; ++x_i)
    {
        for (int y_i = 0; y_i < y_resolution; ++y_i)
        {
            double cornerVals[4];

            double x_orig = x_start + x_i * x_stepSize;
            double y_orig = y_start + y_i * y_stepSize;

            cornerVals[0] = checkVal(x_orig, y_orig);
            cornerVals[1] = checkVal(x_orig, y_orig + y_stepSize);
            cornerVals[2] = checkVal(x_orig + x_stepSize, y_orig);
            cornerVals[3] = checkVal(x_orig + x_stepSize, y_orig + y_stepSize);

            if (((cornerVals[0] > 0 || cornerVals[1] > 0 || cornerVals[2] > 0 || cornerVals[3] > 0) &&
                    (cornerVals[0] < 0 || cornerVals[1] < 0 || cornerVals[2] < 0 || cornerVals[3] < 0))
                    || cornerVals[0] == 0)
            {
                x_data_temp.push_back(x_orig + (x_stepSize / 2));
                y_data_temp.push_back(y_orig + (y_stepSize / 2));
            }
        }
    }


    x_data->push_back(x_data_temp[0]);
    y_data->push_back(y_data_temp[0]);

    x_data->remove(0);
    y_data->remove(0);

    while (!x_data_temp.isEmpty())
    {
        double curX = *(--x_data->end());
        double curY = *(--y_data->end());

        double closedDis = disSquare (curX, curY,
                                      x_data_temp[0], y_data_temp[0]);
        int closedPoint = 0;

        for (int j = 1; j < x_data_temp.size(); ++j)
        {
            double curDis = disSquare(curX, curY,
                                      x_data_temp[j], y_data_temp[j]);

            if (curDis < closedDis)
            {
                closedDis = curDis;
                closedPoint = j;
            }
        }

        x_data->push_back(x_data_temp[closedPoint]);
        y_data->push_back(y_data_temp[closedPoint]);

        x_data_temp.remove(closedPoint);
        y_data_temp.remove(closedPoint);
    }
}


double FunctionOfXAndYIsZero::disSquare (double x1, double y1,
                                         double x2, double y2)
{
    return qPow(x1-x2, 2) + qPow(y1-y2, 2);
}
