#ifndef LOCHISSEARCHRESULTSWIDGET_H
#define LOCHISSEARCHRESULTSWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QGridLayout>

class LocHisSearchResultsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LocHisSearchResultsWidget(QWidget *parent = 0);
    QTextEdit *rawOutPut;
    QGridLayout *layout;
signals:

public slots:

};

#endif // LOCHISSEARCHRESULTSWIDGET_H
