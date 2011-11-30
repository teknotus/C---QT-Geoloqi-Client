#include "lochiswidget.h"

LocHisWidget::LocHisWidget(QWidget *parent) :
    QWidget(parent)
{
    search = new LocationHistorySearchWidget();
    results = new LocHisSearchResultsWidget();
    layout = new QVBoxLayout();
    layout->addWidget(search);
    layout->addWidget(results);
    setLayout(layout);
}
