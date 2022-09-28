#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QScrollArea>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "../plotterwidget.h"

class InputWidget : public QScrollArea
{
    Q_OBJECT
public:
    explicit InputWidget(PlotterWidget *p_myPlotterWidget, QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout *mainLayout;
	QVBoxLayout *inputLayout;
	
	QSpacerItem *vSpacer;
	
	void setupGui();

    void addFunctionInputWidget();

    PlotterWidget *p_myPlotterWidget;
};

#endif // INPUTWIDGET_H
