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

    tracker = new NetTracker();
    connect(search,SIGNAL(request(QUrl)),
            tracker,SLOT(getUrl(QUrl)));
    connect(tracker,SIGNAL(stringRecieved(QString)),
            results,SLOT(stringReply(QString)));
    connect(tracker,SIGNAL(jsonRecieved(QVariant)),
            results,SLOT(jsonReply(QVariant)));
}
