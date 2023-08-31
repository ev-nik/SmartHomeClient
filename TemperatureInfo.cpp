#include "TemperatureInfo.h"
#include "ui_TemperatureInfo.h"
//----------------------------------------------------------------------------

#include <QFile>
#include <QTextStream>
//----------------------------------------------------------------------------

TemperatureInfo::TemperatureInfo(QWidget *parent) :
    Device(parent),
    ui(new Ui::TemperatureInfo)
{
    ui->setupUi(this);

//    isSave = false;

    m_Timer = new QTimer(this);

    connect(m_Timer,          SIGNAL(timeout()), this, SLOT(updateTemperature()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteClick()));

    m_Timer->start(1000);
}
//----------------------------------------------------------------------------

TemperatureInfo::~TemperatureInfo()
{
    delete ui;
}
//----------------------------------------------------------------------------

void TemperatureInfo::updateTemperature()
{
    QPalette pal = ui->temperatureLabel->palette();

    int t = temperature();

    if(t >= 0 && t <=10)
    {
       pal.setColor(QPalette::WindowText, Qt::blue);
    }
    else if(t > 10 && t <= 30)
    {
        pal.setColor(QPalette::WindowText, Qt::green);
    }
    else if(t > 30)
    {
       pal.setColor(QPalette::WindowText, Qt::red);
    }

    ui->temperatureLabel->setPalette(pal);
    ui->temperatureLabel->setText(QString("Температура: %1").arg(t));

    QString qstrT = QString::number(t);

    writeInFile(qstrT);
}
//----------------------------------------------------------------------------

int TemperatureInfo::temperature()
{
    return QTime::currentTime().toString("ss").toInt();
}
//----------------------------------------------------------------------------

void TemperatureInfo::deleteClick()
{
    emit deleteMe();
}
//----------------------------------------------------------------------------

QString TemperatureInfo::nameSensor()
{
    return "temperatureInfo";
}
