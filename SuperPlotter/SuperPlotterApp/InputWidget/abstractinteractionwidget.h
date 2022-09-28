#ifndef ABSTRACTINTERACTIONWIDGET_H
#define ABSTRACTINTERACTIONWIDGET_H

#include <QPushButton>
#include "../plotterwidget.h"

class AbstractInteractionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractInteractionWidget(PlotterWidget *p_plotterWidget,
                                       QWidget *parent = nullptr);

protected:
    QWidget *childWidget;


    void setupParentGui();

    PlotterWidget *p_plotterWidget;

    QPushButton *butUp;
    QPushButton *butDown;

signals:

};

#endif // ABSTRACTINTERACTIONWIDGET_H
