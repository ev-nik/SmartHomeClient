#include "DateTimeInfo.h"
#include "ui_DateTimeInfo.h"
//---------------------------------------------------------------

#include <QDateTime>
//---------------------------------------------------------------

DateTimeInfo::DateTimeInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateTimeInfo)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    connect(timer, SIGNAL(timeout()), this, SLOT(weekDay()));
    timer->start(1000);

    dateTimeLabel = new QLabel(this);
    dayOfWeekLabel = new QLabel(this);
}
//---------------------------------------------------------------

DateTimeInfo::~DateTimeInfo()
{
    delete ui;
}
//---------------------------------------------------------------

void DateTimeInfo::tick()
{
    dateTimeLabel->setGeometry(10, 8, 120, 20);
    QString dateTimeNow = QDateTime::currentDateTime().toString("dd.MM.yyyy  hh:mm:ss");
    dateTimeLabel->setText(dateTimeNow);
}
//---------------------------------------------------------------

void DateTimeInfo::weekDay()
{
    dayOfWeekLabel->setGeometry(10, 30, 100, 20);
    QString dayNow = QDateTime::currentDateTime().toString("dddd");
    dayOfWeekLabel->setText(dayNow);
}
//---------------------------------------------------------------
