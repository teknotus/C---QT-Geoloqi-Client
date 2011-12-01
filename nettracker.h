#ifndef NETTRACKER_H
#define NETTRACKER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QVariant>
#include <QUrl>
#include "netmanager.h"

// debugging stuff remove later
#include <iostream>
#include <QTextStream>
// end debugging stuff

class NetManager; //Forward declaration
class NetTracker : public QObject
{
    Q_OBJECT
public:
    explicit NetTracker(QObject *parent = 0);
    NetTracker(NetManager *,QObject *parent = 0);
    NetManager *netManager;
    QString _token;
    bool emitString;
    bool emitJson;
    void setManager(NetManager*);
    void setToken(QString);
signals:
    void stringRecieved(QString);
    void jsonRecieved(QVariant*);
public slots:
    void getUrl(QUrl);
    void replyFinished(QNetworkReply*);
    void sslErrors(QNetworkReply*, QList<QSslError>);
};

#endif // NETTRACKER_H
