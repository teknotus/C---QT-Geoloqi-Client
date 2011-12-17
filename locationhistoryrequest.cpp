#include "locationhistoryrequest.h"

LocationHistoryRequest::LocationHistoryRequest(QObject *parent) :
    QObject(parent)
{
    _base_url = QString("https://api.geoloqi.com/1/location/history");
    _count = 0; // (default 10)
    //_after(); // timestamp toString(Qt::ISODate)
    //QDateTime _before; // timestamp toString(Qt::ISODate)
    //_sort; // asc || desc
    _accuracy = 0; // (default: 150)
    _thinning = 0; // (default: 0)
    //enum geometry_type _geometry; // circle || rectangle
    //Coordinates *_center; // Required for geometry=circle
    //long _radius; // Required for geometry=circle
    //Coordinates *_sw; // Required for geometry=rectangle
    //Coordinates *_ne; // Required for geometry=rectangle
    //QString _base_url;

}

bool LocationHistoryRequest::isValid()
{
    return true;
}

QUrl LocationHistoryRequest::url()
{
    QUrl url(_base_url);
    if(_count)
    {
        QString count;
        count.setNum(_count);
        url.addQueryItem(QString("count"),count);
    }
    if(_after.isValid())
    {
        QString afterString;
        afterString.setNum(_after.toTime_t());
        url.addQueryItem(QString("after"),afterString);
    }
    if(_before.isValid())
    {
        QString beforeString;
        beforeString.setNum(_before.toTime_t());
        url.addQueryItem(QString("before"),beforeString);
    }
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
    if(_thinning)
    {
        QString thinning;
        thinning.setNum(_thinning);
        url.addQueryItem(QString("thinning"),thinning);
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

LocationHistoryRequest * LocationHistoryRequest::setCount(QString countString)
{
    _count = countString.toLong();
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

