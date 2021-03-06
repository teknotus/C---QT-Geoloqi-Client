#include "loqiwindow.h"

LoqiWindow::LoqiWindow(QWidget *parent)
    : QMainWindow(parent)
{
    settings = new QSettings("ModernTwinPowers", "geoeater");
    authdialog = new AuthDialog();
    connect(authdialog->saveSettingsButton,SIGNAL(clicked()),this,SLOT(authSave()));
    readSettings();
    permanent_token = settings->value("authkey").toString();
    editMenu = menuBar()->addMenu("Edit");
    editAuthKey = new QAction(tr("Edit Auth Key"),this);
    connect(editAuthKey,SIGNAL(triggered()),this,SLOT(showAuthDialog()));
    editMenu->addAction(editAuthKey);
    loqi = new QGeoloqi();
    loqi->setToken(permanent_token);
    outPut = new QTextEdit();
    outPut->setReadOnly(true);
    //outPut->setWordWrapMode(QTextOption::NoWrap);
    setCentralWidget(outPut);
    testButtons = new ApiTestButtons();
    testButtonDock = new QDockWidget(tr("test buttons"));
    testButtonDock->setWidget(testButtons);
    testButtonDock->setAllowedAreas(Qt::LeftDockWidgetArea
                                    | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,testButtonDock);
    manager = new NetManager();
    tracker = new NetTracker(manager);
    tracker->setToken(permanent_token);
    connect(tracker,SIGNAL(stringRecieved(QString)),outPut,SLOT(append(QString)));
    lhr = new LocationHistoryRequest();
    lhr->setCount(10);
    connect(testButtons->getUsernameButton, SIGNAL(clicked()), this, SLOT(onGetUsername()));
    connect(testButtons->getProfileButton, SIGNAL(clicked()), this, SLOT(onGetProfile()));
    connect(testButtons->getLastLocationButton, SIGNAL(clicked()), this, SLOT(onGetLastLocation()));
//    connect(testButtons->getHistoryButton, SIGNAL(clicked()), this, SLOT(onGetHistory()));
    connect(testButtons->getHistoryButton, SIGNAL(clicked()), this, SLOT(onGetHistoriest()));
    connect(testButtons->getPlacesButton, SIGNAL(clicked()), this, SLOT(onGetPlaces()));
}

LoqiWindow::~LoqiWindow()
{
    delete authdialog;
}

void LoqiWindow::readSettings()
{
//    if(!settings->contains("authkey")){
//        authdialog->show();
//    }
//    else
//    {
//        permanent_token = settings->value("authkey").toString();
//        authdialog->authEdit->setText(permanent_token);
//    }
}

void LoqiWindow::writeSettings()
{

}

void LoqiWindow::authSave()
{
    permanent_token = authdialog->authEdit->text();
    settings->setValue("authkey",permanent_token);
    loqi->setToken(permanent_token);
    authdialog->hide();
}
void LoqiWindow::showAuthDialog()
{
    authdialog->show();
}

void LoqiWindow::onGetUsername() {
    QGeoloqiReply* reply = loqi->getUsername();
    connect(reply, SIGNAL(dataReady(QVariant, QGeoloqiReply*)), this, SLOT(appendText(QVariant,QGeoloqiReply*)));
}

void LoqiWindow::onGetProfile() {
    QGeoloqiReply* reply = loqi->getProfile();
    connect(reply, SIGNAL(dataReady(QVariant, QGeoloqiReply*)), this, SLOT(appendText(QVariant,QGeoloqiReply*)));
}

void LoqiWindow::onGetLastLocation() {
    QGeoloqiReply* reply = loqi->getLastLocation();
    connect(reply, SIGNAL(dataReady(QVariant, QGeoloqiReply*)), this, SLOT(appendText(QVariant,QGeoloqiReply*)));
}

void LoqiWindow::onGetHistory() {
    QGeoloqiReply* reply = loqi->getHistory();
    connect(reply, SIGNAL(dataReady(QVariant, QGeoloqiReply*)), this, SLOT(appendText(QVariant,QGeoloqiReply*)));
}
void LoqiWindow::onGetHistoriest() {
//    QGeoloqiReply* reply = lhr->get(loqi);
//    connect(reply, SIGNAL(dataReady(QVariant, QGeoloqiReply*)), this, SLOT(appendText(QVariant,QGeoloqiReply*)));
tracker->getUrl(lhr->url());
}


void LoqiWindow::onGetPlaces() {
    QGeoloqiReply* reply = loqi->getPlaces("","","");
    connect(reply, SIGNAL(dataReady(QVariant, QGeoloqiReply*)), this, SLOT(appendText(QVariant,QGeoloqiReply*)));
}

void LoqiWindow::appendText(QVariant text, QGeoloqiReply* reply) {
//    outPut->append(QString(loqi->encodeJson(text)));
    outPut->append(text.toString());
    reply->deleteLater();
}
