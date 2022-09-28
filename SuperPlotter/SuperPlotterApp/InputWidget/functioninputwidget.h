#ifndef FUNCTIONINPUTWIDGET_H
#define FUNCTIONINPUTWIDGET_H

#include "abstractinteractionwidget.h"

#include <QLineEdit>
#include <QLabel>

#include "Functions/function.h"

#define RESOLUTION 100

class FunctionInputWidget : public AbstractInteractionWidget
{
public:
    FunctionInputWidget(PlotterWidget *p_plotterWidget, QWidget *parent = nullptr);

private:
    void setupChildGui();

    QLineEdit *functionInput;
    QLabel *errReporter;

    Function *myFunction;

    class ReplotWorker : public QThread
    {
    public:
        explicit ReplotWorker (PlotterWidget *p_plotterWidget,
                               Function *myFunction,
                               QWidget *parent = nullptr);
        void run() override;

    private:
        PlotterWidget *p_plotterWidget;
        Function *myFunction;
    };


private slots:
    void inputChanged();
    void replot();
};


#endif // FUNCTIONINPUTWIDGET_H
