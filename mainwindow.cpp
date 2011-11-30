#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    settings = new QSettings("ModernTwinPowers", "geoeater");
    authdialog = new AuthDialog();
    connect(authdialog->saveSettingsButton,SIGNAL(clicked()),this,SLOT(authSave()));
    readSettings();
    editMenu = menuBar()->addMenu("Edit");
    editAuthKey = new QAction(tr("Edit Auth Key"),this);
    connect(editAuthKey,SIGNAL(triggered()),this,SLOT(showAuthDialog()));
    editMenu->addAction(editAuthKey);
    loc_his = new LocHisWidget();
    setCentralWidget(loc_his);
}

void MainWindow::readSettings()
{
    if(!settings->contains("authkey")){
        authdialog->show();
    }
    else
    {
        permanent_token = settings->value("authkey").toString();
        authdialog->authEdit->setText(permanent_token);
    }
}

void MainWindow::showAuthDialog()
{
    authdialog->show();
}

void MainWindow::authSave()
{
    permanent_token = authdialog->authEdit->text();
    settings->setValue("authkey",permanent_token);
    authdialog->hide();
}
