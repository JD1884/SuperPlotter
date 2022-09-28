#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupGui();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setupGui()
{   
    myPlotterWidget = new PlotterWidget();
    myInputWidget = new InputWidget(myPlotterWidget);

    QHBoxLayout *myLayout = new QHBoxLayout();

    myLayout->addWidget(myInputWidget);
    myLayout->addWidget(myPlotterWidget);

    myLayout->setStretchFactor(myInputWidget, 2);
    myLayout->setStretchFactor(myPlotterWidget, 3);

    centralWidget()->setLayout(myLayout);
}
