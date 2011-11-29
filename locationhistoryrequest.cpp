#include "locationhistoryrequest.h"

LocationHistoryRequest::LocationHistoryRequest(QObject *parent) :
    QObject(parent)
{
    _base_url = QString("https://api.geoloqi.com/1/location/history");
}

bool LocationHistoryRequest::isValid()
{
    return true;
}

QUrl LocationHistoryRequest::url()
{
    QUrl url(_base_url);
//    url.addQueryItem(QString("oauth_token"), loki->token);
    if(_count)
    {
        QString count;
        count.setNum(_count);
        url.addQueryItem(QString("count"),count);
    }
    if(_after.isValid())
        url.addQueryItem(QString("after"),_after.toString(Qt::ISODate));
    if(_before.isValid())
        url.addQueryItem(QString("before"),_before.toString(Qt::ISODate));

    switch(_sort)
    {
    case no_sort:
        break;
    case asc:
        url.addQueryItem(QString("sort"),QString("asc"));
        break;
    case desc:
        url.addQueryItem(QString("sort"),QString("desc"));
        break;
    default:
        break;
    }
    if(_accuracy)
    {
        QString accuracy;
        accuracy.setNum(_count);
        url.addQueryItem(QString("accuracy"),accuracy);
    }
    if(_accuracy)
    {
        QString accuracy;
        accuracy.setNum(_accuracy);
        url.addQueryItem(QString("accuracy"),accuracy);
    }
    switch(_geometry)
    {
    case no_geometry:
        break;
    case circle:
        url.addQueryItem(QString("geometry"),QString("circle"));
        break;
    case rectangle:
        url.addQueryItem(QString("geometry"),QString("rectangle"));
        break;
    default:
        break;
    }
    if(_geometry == circle)
    {
        url.addQueryItem(QString("center"),_center->toString());
        QString radius;
        radius.setNum(_radius);
        url.addQueryItem(QString("radius"),radius);
    }else if (_geometry == rectangle) {
        url.addQueryItem(QString("sw"),_sw->toString());
        url.addQueryItem(QString("ne"),_ne->toString());
    }
    return url;
}

/* Setters */

LocationHistoryRequest * LocationHistoryRequest::setCount(long count)
{
    _count = count;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setAfter(QDateTime after)
{
    _after = after;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setBefore(QDateTime before)
{
    _before = before;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setSort(enum sort_direction sort)
{
    _sort = sort;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setAccuracy(long accuracy)
{
    _accuracy = accuracy;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setThinning(long thinning)
{
    _thinning = thinning;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setGeometry(enum geometry_type geometry)
{
    _geometry = geometry;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setCenter(Coordinates *center)
{
    _center = center;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setRadius(long radius)
{
    _radius = radius;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setSW(Coordinates *sw)
{
    _sw = sw;
    return this;
}

LocationHistoryRequest * LocationHistoryRequest::setNE(Coordinates *ne)
{
    _ne = ne;
    return this;
}

