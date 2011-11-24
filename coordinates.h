#ifndef COORDINATES_H
#define COORDINATES_H

#include <QStringBuilder>

class Coordinates
{
public:
    Coordinates();
    Coordinates(double,double);
    double latitude;
    double longitude;
    QString toString();

};

#endif // COORDINATES_H
