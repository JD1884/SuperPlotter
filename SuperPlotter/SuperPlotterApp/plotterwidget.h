#ifndef PLOTTERWIDGET_H
#define PLOTTERWIDGET_H

#include "qcustomplot.h"

class PlotterWidget : public QCustomPlot
{
    Q_OBJECT
public:
    explicit PlotterWidget(QWidget *parent = nullptr);

signals:

};

#endif // PLOTTERWIDGET_H
