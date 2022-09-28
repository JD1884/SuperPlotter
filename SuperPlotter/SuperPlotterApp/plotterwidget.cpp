#include "plotterwidget.h"

PlotterWidget::PlotterWidget(QWidget *parent)
    : QCustomPlot{parent}
{
    xAxis->setRange(-5, 5);
    yAxis->setRange(-5, 5);
}
