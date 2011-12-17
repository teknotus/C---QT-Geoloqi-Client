#include "lochissearchresultswidget.h"

LocHisSearchResultsWidget::LocHisSearchResultsWidget(QWidget *parent) :
    QWidget(parent)
{
    rawOutPut = new QTextEdit();
    rawOutPut->setReadOnly(true);
    clearButton = new QPushButton(tr("Clear Results"));
    resultViews = new QTabWidget();
    resultsTable = new QTableWidget(0,8);
    tableHeaders << "date_ts"
                 << "altitude"
                 << "heading"
                 << "horizontal_accuracy"
                 << "latitude"
                 << "longitude"
                 << "speed"
                 << "vertical_accuracy";

    resultsTable->setHorizontalHeaderLabels(tableHeaders);
    scene = new QGraphicsScene();
    mapView = new QGraphicsView(scene);
    mapTabId = resultViews->addTab(mapView,tr("map"));
    tableTabId = resultViews->addTab(resultsTable,tr("table"));
    rawTabId = resultViews->addTab(rawOutPut,tr("raw output"));
    layout = new QGridLayout;
    layout->addWidget(resultViews,0,0,1,2);
//    layout->addWidget(rawOutPut,0,0,1,2);
    layout->addWidget(clearButton,1,0);
    setLayout(layout);
    connect(clearButton,SIGNAL(clicked()),
            rawOutPut,SLOT(clear()));
    connect(clearButton,SIGNAL(clicked()),
            resultsTable,SLOT(clear()));
    connect(clearButton,SIGNAL(clicked()),
            this,SLOT(clearTable()));
    connect(clearButton,SIGNAL(clicked()),
            scene,SLOT(clear()));
}

void LocHisSearchResultsWidget::stringReply(QString stringResult)
{
    rawOutPut->append(stringResult);
}

void LocHisSearchResultsWidget::jsonReply(QVariant parsedResult)
{
    QTextStream out(stdout); //Debugging stuff
    out << "in jsonReply" << endl;
    QVariantMap rootmap = parsedResult.toMap();
    QMapIterator<QString,QVariant> rootmapi(rootmap);
    while(rootmapi.hasNext())
    {
        rootmapi.next();
        out << rootmapi.key() << endl;
    }
    resultsTable->setHorizontalHeaderLabels(tableHeaders);
    QVariantMap bounds = rootmap.value("bounds").toMap();
    QVariantMap sw = bounds.value("sw").toMap();
    double sw_lat = sw.value("latitude").toDouble();
    double sw_lon = sw.value("longitude").toDouble();
    QVariantMap ne = bounds.value("ne").toMap();
    double ne_lat = ne.value("latitude").toDouble();
    double ne_lon = ne.value("longitude").toDouble();
    double viewWidth = (ne_lon - sw_lon);
    double viewHight = (ne_lat - sw_lat);
    QSize mapSize = mapView->size();
    double wscale = (mapSize.width() - 3 ) / viewWidth;
    double hscale = (mapSize.height() - 3 ) / viewHight;
    double scale = wscale < hscale ? wscale : hscale;
    QRectF viewrect(0.0,0.0,viewWidth*scale,viewHight*scale);
    out << "topleft x:" << sw_lon << " y:" << ne_lat;
    out << " width:" << viewWidth << " hight:" << viewHight << endl;
    scene->setSceneRect(viewrect);
    //    mapView->setSceneRect(viewrect);
    //mapView;
//    mapSize.;
//    mapView->scale(0.5,0.5);
//    resultsTable->set
    int row = 0;
    double prevLat = 0,prevLong = 0;
    QBrush mapBrush(Qt::green, Qt::SolidPattern);
    QPen mapPen(mapBrush,3,Qt::SolidLine);
    QVariantList pointslist = rootmap["points"].toList();
    QListIterator<QVariant> pointslisti(pointslist);
    while(pointslisti.hasNext())
    {
        resultsTable->insertRow(row);
        //out << "row:" << row << endl;
        QVariant point = pointslisti.next();
        QVariantMap pointMap = point.toMap();
        QString date_string = pointMap["date_ts"].toString();
        //out << "date:" << date_string << endl;
        QTableWidgetItem *date_ts = new QTableWidgetItem(date_string);
        resultsTable->setItem(row,0,date_ts);
        QVariantMap positionMap = pointMap.value("location").toMap().value("position").toMap();
        QTableWidgetItem *altitude = new QTableWidgetItem(positionMap.value("altitude").toString());
        resultsTable->setItem(row,1,altitude);
        QTableWidgetItem *heading = new QTableWidgetItem(positionMap.value("heading").toString());
        resultsTable->setItem(row,2,heading);
        QTableWidgetItem *horizontal_accuracy = new QTableWidgetItem(positionMap.value("horizontal_accuracy").toString());
        resultsTable->setItem(row,3,horizontal_accuracy);
        QTableWidgetItem *latitude = new QTableWidgetItem(positionMap.value("latitude").toString());
        double lat = positionMap.value("latitude").toDouble() - ne_lat;
        resultsTable->setItem(row,4,latitude);
        QTableWidgetItem *longitude = new QTableWidgetItem(positionMap.value("longitude").toString());
        double lon = positionMap.value("longitude").toDouble() - sw_lon;
        resultsTable->setItem(row,5,longitude);
        if(row)
        {
//            double s = 3000.0; //scale
//            double s = 1;
            double s = scale;
            double plon,plat,clon,clat;
            plon = prevLong*s;
            plat = prevLat*s;
            clon = lon*s;
            clat = lat*s;
            out << "drawing line x1:" << plon << " y1:" << plat << " x2:" << clon << " y2:" << clat << endl;
            scene->addLine(prevLong * s,-prevLat * s,lon * s,-lat * s,mapPen);
        }
        prevLat = lat;
        prevLong = lon;

        QTableWidgetItem *speed = new QTableWidgetItem(positionMap.value("speed").toString());
        resultsTable->setItem(row,6,speed);
        QTableWidgetItem *vertical_accuracy = new QTableWidgetItem(positionMap.value("vertical_accuracy").toString());
        resultsTable->setItem(row,7,vertical_accuracy);

        row++;
    }
}
void LocHisSearchResultsWidget::clearTable()
{
    resultsTable->setRowCount(0);
}
