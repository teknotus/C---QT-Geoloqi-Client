#ifndef LOQIWINDOW_H
#define LOQIWINDOW_H

#include <QtGui/QMainWindow>
#include <QSettings>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QString>
#include <QTextEdit>
#include <QDockWidget>
#include "authdialog.h"
#include "qgeoloqi.h"
#include "apitestbuttons.h"
#include "locationhistoryrequest.h"
#include "netmanager.h"
#include "nettracker.h"

class LoqiWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoqiWindow(QWidget *parent = 0);
    ~LoqiWindow();
    void readSettings();
    void writeSettings();
    AuthDialog *authdialog;
    QSettings *settings;
    QMenu *editMenu;
    QAction *editAuthKey;
    QString permanent_token;
    QTextEdit *outPut;
    ApiTestButtons *testButtons;
    QDockWidget *testButtonDock;
    LocationHistoryRequest *lhr;
    NetManager *manager;
    NetTracker *tracker;

public slots:
    void authSave();
    void showAuthDialog();
    void appendText(QVariant, QGeoloqiReply*);
    void onGetUsername();
    void onGetProfile();
    void onGetLastLocation();
    void onGetHistory();
    void onGetHistoriest();
    void onGetPlaces();

private:
    QGeoloqi* loqi;
};

#endif // LOQIWINDOW_H
