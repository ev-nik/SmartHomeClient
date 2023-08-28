#include "DateTimeInfo.h"
#include "ui_DateTimeInfo.h"
//----------------------------------------------------------------------------

#include <QString>
#include <QDateTime>
#include <QDate>
#include <QVBoxLayout>

//----------------------------------------------------------------------------

//#define FILE_PATH "E:/prog.txt"
//----------------------------------------------------------------------------

DateTimeInfo::DateTimeInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateTimeInfo)
{
    ui->setupUi(this);

//    isSave = false;

    m_Timer = new QTimer(this);

    connect(m_Timer,          SIGNAL(timeout()),     this, SLOT(tick()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteClick()));
    connect(m_Timer,          SIGNAL(timeout()),     this, SLOT(updateWeekDay()));

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

    ui->dateLabel->setText(QString("Дата: %1").arg(dateNow));
    ui->timeLabel->setText(QString("Время: %1").arg(timeNow));

    writeInFile(dateNow);
    writeInFile(timeNow);

}
//----------------------------------------------------------------------------

void DateTimeInfo::deleteClick()
{
    emit deleteMe();
}
//----------------------------------------------------------------------------

void DateTimeInfo::updateWeekDay()
{
    QString dayNow = QDate::currentDate().toString("dddd");
    dayNow[0] = dayNow[0].toUpper();

    writeFiles(dayNow);
    writeFiles("\n");

    ui->dayOfWeekLabel->setText(dayNow);
}
//----------------------------------------------------------------------------

void DateTimeInfo::writeInFile(QString qs)
{
    QFile file(fileAdress);

    if(file.open(QIODevice::Append))
    {
        QTextStream prog(&file); // С помощью такой конструкции
        prog << qs;  // передаем данные в файл

        file.close();
    }
}
//----------------------------------------------------------------------------

//void DateTimeInfo::setSave(bool x)
//{
//    isSave = x;
//}
//----------------------------------------------------------------------------

void DateTimeInfo::setFileAdress(QString addres)
{
    fileAdress = addres;
}
//----------------------------------------------------------------------------
