#ifndef LOCATIONHISTORYREQUEST_H
#define LOCATIONHISTORYREQUEST_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include "coordinates.h"
#include "qgeoloqi.h"
#include "qgeoloqireply.h"

class LocationHistoryRequest : public QObject
{
    Q_OBJECT
public:
    explicit LocationHistoryRequest(QObject *parent = 0);
    enum sort_direction {
        no_sort,
        asc,
        desc
    };

    enum geometry_type {
        no_geometry,
        circle,
        rectangle
    };

    /* Setters */

    QUrl url();
    bool isValid(); // checks if object has required request values
    /*long count();
    QDateTime after();
    */

    long _count; // (default 10)
    QDateTime _after; // timestamp toString(Qt::ISODate)
    QDateTime _before; // timestamp toString(Qt::ISODate)
    enum sort_direction _sort; // asc || desc
    long _accuracy; // (default: 150)
    long _thinning; // (default: 0)
    enum geometry_type _geometry; // circle || rectangle
    Coordinates *_center; // Required for geometry=circle
    long _radius; // Required for geometry=circle
    Coordinates *_sw; // Required for geometry=rectangle
    Coordinates *_ne; // Required for geometry=rectangle
    QString _base_url;

signals:

public slots:
    LocationHistoryRequest * setCount(long);
    LocationHistoryRequest * setAfter(QDateTime);
    LocationHistoryRequest * setBefore(QDateTime);
    LocationHistoryRequest * setSort(enum sort_direction);
    LocationHistoryRequest * setAccuracy(long);
    LocationHistoryRequest * setThinning(long);
    LocationHistoryRequest * setGeometry(enum geometry_type);
    LocationHistoryRequest * setCenter(Coordinates*);
    LocationHistoryRequest * setRadius(long);
    LocationHistoryRequest * setSW(Coordinates*);
    LocationHistoryRequest * setNE(Coordinates*);

};

#endif // LOCATIONHISTORYREQUEST_H
