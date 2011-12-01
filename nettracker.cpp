#include "nettracker.h"

NetTracker::NetTracker(QObject *parent) :
    QObject(parent)
{
}

NetTracker::NetTracker(NetManager *_netManager,QObject *parent) :
    QObject(parent)
{
    netManager = _netManager;
    emitString = true;
}

void NetTracker::setManager(NetManager *_netManager)
{
    netManager = _netManager;
}

void NetTracker::setToken(QString token)
{
    _token = token;
}

void NetTracker::getUrl(QUrl url)
{
    url.addQueryItem(QString("oauth_token"), _token);

    QTextStream out(stdout);
    out << url.toString();

    QNetworkRequest request = QNetworkRequest(url);
    request.setOriginatingObject(this);
    netManager->manager->get(request);
}

void NetTracker::replyFinished(QNetworkReply *reply)
{
QByteArray response = reply->readAll();
emit stringRecieved(QString(response));
reply->deleteLater();
}

void NetTracker::sslErrors(QNetworkReply*, QList<QSslError>)
{

}
