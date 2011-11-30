#ifndef LOCATIONHISTORYSEARCHWIDGET_H
#define LOCATIONHISTORYSEARCHWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include "locationhistoryrequest.h"

class LocationHistorySearchWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LocationHistorySearchWidget(QWidget *parent = 0);
    QLabel *afterLabel;
    QDateTimeEdit *after;
    QLabel *beforeLabel;
    QDateTimeEdit *before;
    QHBoxLayout *timeRangeEdit;
    QLabel *countLabel;
    QLineEdit *count;
    QHBoxLayout *filterLayout;
    QPushButton *searchButton;
    QVBoxLayout *searchLayout;
    LocationHistoryRequest *locHisRequest;

signals:
    void request(LocationHistoryRequest*);
public slots:
    void sendReqest();

};

#endif // LOCATIONHISTORYSEARCHWIDGET_H
