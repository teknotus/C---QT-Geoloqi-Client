#ifndef COORDINATES_H
#define COORDINATES_H

#include <QObject>
#include <QStringBuilder>

class Coordinates : public QObject
{
    Q_OBJECT
public:
    explicit Coordinates(QObject *parent = 0);
    double latitude;
    double longitude;
    QString toString();
signals:

public slots:

};

#endif // COORDINATES_H
