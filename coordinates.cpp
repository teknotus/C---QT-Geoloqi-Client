#include "coordinates.h"

Coordinates::Coordinates()
{
    latitude = 0;
    longitude = 0;
}
Coordinates::Coordinates(double _latitude, double _longitude)
{
    latitude = _latitude;
    longitude = _longitude;
}

QString Coordinates::toString()
{
    QString latitude_str,longitude_str;
    latitude_str.setNum(latitude);
    longitude_str.setNum(longitude);
    return latitude_str % "," % longitude_str;
}
