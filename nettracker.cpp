#include "nettracker.h"

NetTracker::NetTracker(QObject *parent) :
    QObject(parent)
{
    emitString = true;
    emitJson = true;
    parser = new QJson::Parser();
}

NetTracker::NetTracker(NetManager *_netManager,QObject *parent) :
    QObject(parent)
{
    netManager = _netManager;
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

    QTextStream out(stdout); //Debugging stuff
    out << url.toString() << endl; //FIXME

    QNetworkRequest request = QNetworkRequest(url);
    request.setOriginatingObject(this);
    netManager->manager->get(request);
}

void NetTracker::replyFinished(QNetworkReply *reply)
{
    QByteArray response = reply->readAll();
    if(emitString)
        emit stringRecieved(QString(response));
    if(emitJson)
    {
        bool parse_ok = false;
        QVariant dataTree = parser->parse(response,&parse_ok);
        if(!parse_ok)
        {
            // do something FIXME
        }
        emit jsonRecieved(dataTree);
    }
    reply->deleteLater();
}

void NetTracker::sslErrors(QNetworkReply*, QList<QSslError>)
{
// FIXME
}
