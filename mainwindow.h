#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "authdialog.h"
#include "lochiswidget.h"
#include "netmanager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void readSettings();
    //void writeSettings();
    AuthDialog *authdialog;
    QSettings *settings;
    QMenu *editMenu;
    QAction *editAuthKey;
    QString permanent_token;
    LocHisWidget *loc_his;
    NetManager *manager;
signals:

public slots:
    void showAuthDialog();
    void authSave();
};

#endif // MAINWINDOW_H
