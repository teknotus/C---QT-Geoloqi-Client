#include "lochissearchresultswidget.h"

LocHisSearchResultsWidget::LocHisSearchResultsWidget(QWidget *parent) :
    QWidget(parent)
{
    rawOutPut = new QTextEdit();
    rawOutPut->setReadOnly(true);
    layout = new QGridLayout;
    layout->addWidget(rawOutPut,0,0);
    setLayout(layout);
}

void LocHisSearchResultsWidget::stringReply(QString stringResult)
{
    rawOutPut->append(stringResult);
}
