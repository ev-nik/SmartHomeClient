#include "DateTimeInfo.h"
#include "ui_DateTimeInfo.h"
//----------------------------------------------------------------------------

#include <QString>
#include <QDateTime>
#include <QDate>
#include <QVBoxLayout>
//----------------------------------------------------------------------------

DateTimeInfo::DateTimeInfo(QWidget *parent) :
    Device(parent),
    ui(new Ui::DateTimeInfo)
{
    ui->setupUi(this);

    m_Timer = new QTimer(this);

    connect(m_Timer,          SIGNAL(timeout()),     this, SLOT(tick()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteClick()));

    m_Timer->start(1000);
}
//----------------------------------------------------------------------------

DateTimeInfo::~DateTimeInfo()
{
    delete ui;
}
//----------------------------------------------------------------------------
void DateTimeInfo::tick()
{
    QString dateNow = QDateTime::currentDateTime().toString("dd.MM.yyyy");
    QString timeNow = QDateTime::currentDateTime().toString("hh:mm:ss ");
    QString dayNow  = QDateTime::currentDateTime().toString("dddd");

    dayNow[0] = dayNow[0].toUpper();

    ui->dateLabel     ->setText(QString("Дата: %1").arg(dateNow));
    ui->timeLabel     ->setText(QString("Время: %1").arg(timeNow));
    ui->dayOfWeekLabel->setText(dayNow);

    writeInFile(dateNow + " " + timeNow + ";" + dayNow, CSV);
}
//----------------------------------------------------------------------------

void DateTimeInfo::deleteClick()
{
    emit deleteMe();
}
//----------------------------------------------------------------------------

QString DateTimeInfo::nameSensor()
{
    return "dateTimeInfo";
}
