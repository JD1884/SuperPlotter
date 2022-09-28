#ifndef CONSTANTMANIPULATORWIDGET_H
#define CONSTANTMANIPULATORWIDGET_H

#include "abstractinteractionwidget.h"

class ConstantManipulatorWidget : public AbstractInteractionWidget
{
public:
    ConstantManipulatorWidget(PlotterWidget *p_plotterWidget, QWidget *parent = nullptr);

private:
    void setupChildGui();
};

#endif // CONSTANTMANIPULATORWIDGET_H
