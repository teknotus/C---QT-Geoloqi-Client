#ifndef LOCHISWIDGET_H
#define LOCHISWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "locationhistorysearchwidget.h"
#include "lochissearchresultswidget.h"
#include "nettracker.h"

class LocHisWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LocHisWidget(QWidget *parent = 0);
    LocationHistorySearchWidget *search;
    LocHisSearchResultsWidget *results;
    QVBoxLayout *layout;
    NetTracker *tracker;
signals:

public slots:

};

#endif // LOCHISWIDGET_H
