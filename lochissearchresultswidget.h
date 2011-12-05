#ifndef LOCHISSEARCHRESULTSWIDGET_H
#define LOCHISSEARCHRESULTSWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>
#include <QMapIterator>
#include <QListIterator>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPen>
#include <QBrush>
#include <QRectF>

// debugging stuff remove later
#include <iostream>
#include <QTextStream>
// end debugging stuff

class LocHisSearchResultsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LocHisSearchResultsWidget(QWidget *parent = 0);
    QTextEdit *rawOutPut;
    QGridLayout *layout;
    QPushButton *clearButton;
    QTabWidget *resultViews;
    int rawTabId;
    QTableWidget *resultsTable;
    int tableTabId;
    QGraphicsScene *scene;
    QGraphicsView *mapView;
    int mapTabId;
    //QBrush *mapBrush;


signals:

public slots:
    void stringReply(QString);
    void jsonReply(QVariant);
    void clearTable();
};

#endif // LOCHISSEARCHRESULTSWIDGET_H
