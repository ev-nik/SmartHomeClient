#include "DateTimeInfo.h"
#include "ui_DateTimeInfo.h"
//---------------------------------------------------------------

#include <QDateTime>
#include <QVBoxLayout>
//---------------------------------------------------------------

DateTimeInfo::DateTimeInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateTimeInfo)
{
    ui->setupUi(this);

    m_Timer = new QTimer(this);

    connect(m_Timer, SIGNAL(timeout()), this, SLOT(tick()));
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(updateWeekDay()));
    m_Timer->start(1000);
}
//---------------------------------------------------------------

DateTimeInfo::~DateTimeInfo()
{
    delete ui;
}
//---------------------------------------------------------------

void DateTimeInfo::tick()
{
    QString dateTimeNow = QDateTime::currentDateTime().toString("dd.MM.yyyy  hh:mm:ss");
    ui->dateTimeLabel->setText(dateTimeNow);
}
//---------------------------------------------------------------

void DateTimeInfo::updateWeekDay()
{
    QString dayNow = QDateTime::currentDateTime().toString("dddd");
    dayNow[0] = dayNow[0].toUpper(); // Способ поднятия первой буквы строки
                                     // в верхний регистр (заглавная буква)

    ui->dayOfWeekLabel->setText(dayNow);
}
//---------------------------------------------------------------
