#include "netmanager.h"

NetManager::NetManager(QObject *parent) :
    QObject(parent)
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
            this, SLOT(sslErrors(QNetworkReply*, QList<QSslError>)));

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
}

void NetManager::replyFinished(QNetworkReply* netReply)
{
    QNetworkRequest netRequest = netReply->request();
    QObject *original = netRequest.originatingObject();
    NetTracker *tracker = static_cast<NetTracker *>(original);
    connect(this,SIGNAL(replyRecieved(QNetworkReply*)),
            tracker,SLOT(replyFinished(QNetworkReply*)));
    emit replyRecieved(netReply);
    disconnect(this,SIGNAL(replyRecieved(QNetworkReply*)),
               tracker,SLOT(replyFinished(QNetworkReply*)));
}

void NetManager::sslErrors(QNetworkReply *netReply, QList<QSslError> errors)
{
    QNetworkRequest netRequest = netReply->request();
    QObject *original = netRequest.originatingObject();
    NetTracker *tracker = static_cast<NetTracker *>(original);
    connect(this,SIGNAL(replySslErrors(QNetworkReply*,QList<QSslError>)),
            tracker,SLOT(replyFinished(QNetworkReply*,QList<QSslError>)));
    emit replySslErrors(netReply,errors);
}
