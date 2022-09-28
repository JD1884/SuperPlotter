#include "inputwidget.h"

#include <QLabel>

#include "functioninputwidget.h"

InputWidget::InputWidget(PlotterWidget *p_myPlotterWidget, QWidget *parent)
    : QScrollArea{ parent }, p_myPlotterWidget(p_myPlotterWidget)
{
	setupGui();

    addFunctionInputWidget();
}


void InputWidget::setupGui()
{
    setWidgetResizable(true);
    setAlignment(Qt::AlignTop);
	mainLayout = new QVBoxLayout();
	inputLayout = new QVBoxLayout();
    vSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
	
	setFrameShape(QFrame::NoFrame);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
    QWidget *inputWidget = new QWidget();
    inputWidget->setLayout(inputLayout);

    mainLayout->addWidget(inputWidget);
	mainLayout->addItem(vSpacer);
	
	setWidget(new QWidget());
    widget()->setLayout(mainLayout);
}


void InputWidget::addFunctionInputWidget()
{
    inputLayout->addWidget(new FunctionInputWidget(p_myPlotterWidget));
}
