#include "lochissearchresultswidget.h"

LocHisSearchResultsWidget::LocHisSearchResultsWidget(QWidget *parent) :
    QWidget(parent)
{
    rawOutPut = new QTextEdit();
    rawOutPut->setReadOnly(true);
    clearButton = new QPushButton(tr("Clear Results"));
    resultViews = new QTabWidget();
    resultsTable = new QTableWidget(0,8);
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
    int row = 0;
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
        resultsTable->setItem(row,4,latitude);
        QTableWidgetItem *longitude = new QTableWidgetItem(positionMap.value("longitude").toString());
        resultsTable->setItem(row,5,longitude);
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
