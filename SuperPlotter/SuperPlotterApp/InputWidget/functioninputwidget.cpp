#include "functioninputwidget.h"

#include <QVBoxLayout>

#include "formulacreator.h"

FunctionInputWidget::FunctionInputWidget(PlotterWidget *p_plotterWidget, QWidget *parent)
    :AbstractInteractionWidget(p_plotterWidget, parent)
{
    setupChildGui();

    connect(functionInput, &QLineEdit::textChanged, this, &FunctionInputWidget::inputChanged);

    p_plotterWidget->addGraph();
}


void FunctionInputWidget::setupChildGui()
{
    functionInput = new QLineEdit("");
    errReporter = new QLabel("Error messages");

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addWidget(functionInput);
    mainLayout->addWidget(errReporter);

    childWidget->setLayout(mainLayout);
}


void FunctionInputWidget::inputChanged()
{
    FormulaCreator *myFormulaCreator = new FormulaCreator();
    myFunction = myFormulaCreator->createFunction(functionInput->text());

    if (myFunction == nullptr)
    {
        errReporter->setText(myFormulaCreator->getErrMessage());
    } else
    {
        errReporter->setText("");
    }

    replot();
}


void FunctionInputWidget::replot()
{
    if (myFunction != nullptr)
    {
        ReplotWorker *myReplotWorker = new ReplotWorker(p_plotterWidget, myFunction, this);
        connect(myReplotWorker, &ReplotWorker::finished, myReplotWorker, &QObject::deleteLater);
        myReplotWorker->start();
    }
}


FunctionInputWidget::ReplotWorker::ReplotWorker (PlotterWidget *p_plotterWidget, Function *myFunction, QWidget *parent)
    :QThread(parent), p_plotterWidget(p_plotterWidget), myFunction(myFunction)
{}



void FunctionInputWidget::ReplotWorker::run ()
{
    QVector <double> *x_data = new QVector<double> (RESOLUTION);
    QVector <double> *y_data = new QVector<double> (RESOLUTION);


    myFunction->getPlotPoints(p_plotterWidget->xAxis->range().lower, p_plotterWidget->xAxis->range().upper,
                              RESOLUTION,
                              p_plotterWidget->yAxis->range().lower, p_plotterWidget->yAxis->range().upper,
                              RESOLUTION,
                              x_data,
                              y_data);

    p_plotterWidget->graph(0)->setData(*x_data, *y_data);
    p_plotterWidget->replot();

    delete x_data;
    delete y_data;
}
