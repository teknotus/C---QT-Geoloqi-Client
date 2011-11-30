#include "locationhistorysearchwidget.h"

LocationHistorySearchWidget::LocationHistorySearchWidget(QWidget *parent) :
    QWidget(parent)
{
    QDateTime now(QDateTime::currentDateTime());
    beforeLabel = new QLabel(tr("Before"));
    before = new QDateTimeEdit(now);
    //before->setDisplayFormat(Qt::ISODate);
    before->setCalendarPopup(true);
    beforeLabel->setBuddy(before);
    afterLabel = new QLabel(tr("After"));
    after = new QDateTimeEdit(now.addDays(-7));
    //after->setDisplayFormat(Qt::ISODate);
    after->setCalendarPopup(true);
    afterLabel->setBuddy(after);
    countLabel = new QLabel(tr("Count"));
    count = new QLineEdit();
    //count->setMask("9");
    countLabel->setBuddy(count);
    timeRangeEdit = new QHBoxLayout();
    timeRangeEdit->addWidget(afterLabel);
    timeRangeEdit->addWidget(after);
    timeRangeEdit->addStretch();
    timeRangeEdit->addWidget(beforeLabel);
    timeRangeEdit->addWidget(before);
    filterLayout = new QHBoxLayout();
    filterLayout->addWidget(countLabel);
    filterLayout->addWidget(count);
    searchButton = new QPushButton(tr("Search"));
    searchLayout = new QVBoxLayout();
    searchLayout->addLayout(timeRangeEdit);
    searchLayout->addLayout(filterLayout);
    searchLayout->addWidget(searchButton);
    setLayout(searchLayout);

    locHisRequest = new LocationHistoryRequest();
    connect(after,SIGNAL(dateTimeChanged(QDateTime)),
            locHisRequest,SLOT(setAfter(QDateTime)));
    connect(before,SIGNAL(dateTimeChanged(QDateTime)),
            locHisRequest,SLOT(setBefore(QDateTime)));
    //connect(count,SIGNAL(textChanged(QString.toLong())),
    //        locHisRequest,SLOT(setCount(long)));
    connect(searchButton,SIGNAL(clicked()),this,SLOT(sendReqest()));
}

void LocationHistorySearchWidget::sendReqest()
{
    emit request(locHisRequest);
}
