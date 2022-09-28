#include "abstractinteractionwidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

AbstractInteractionWidget::AbstractInteractionWidget(PlotterWidget *p_plotterWidget,
                                                     QWidget *parent)
    : QWidget{parent}, childWidget(new QWidget()), p_plotterWidget(p_plotterWidget)
{
    setupParentGui();
}


void AbstractInteractionWidget::setupParentGui()
{
    butUp = new QPushButton ("up");
    butDown = new QPushButton ("down");

    QVBoxLayout *upDownLayout = new QVBoxLayout();

    upDownLayout->addWidget(butUp);
    upDownLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    upDownLayout->addWidget(butDown);

    QHBoxLayout *mainLayout = new QHBoxLayout();

    mainLayout->addLayout(upDownLayout);
    mainLayout->addWidget(childWidget);

    setLayout(mainLayout);
}
