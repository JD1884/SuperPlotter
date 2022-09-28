#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "InputWidget/inputwidget.h"
#include "plotterwidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupGui();

    InputWidget *myInputWidget;
    PlotterWidget *myPlotterWidget;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
