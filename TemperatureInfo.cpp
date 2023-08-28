#include "TemperatureInfo.h"
#include "ui_TemperatureInfo.h"
//----------------------------------------------------------------------------

#include <QFile>
#include <QTextStream>
//----------------------------------------------------------------------------

//#define FILE_PATH "E:/prog.txt"
//----------------------------------------------------------------------------


TemperatureInfo::TemperatureInfo(QWidget *parent) :
    QWidget(parent),
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

        writeInFile(t);
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

void TemperatureInfo::writeInFile(int temp)
{
    QFile file(fileAdress);

    if(file.open(QIODevice::Append))
    {
        QTextStream prog(&file);
        prog << " t°C" << temp << " ";

        file.close();
    }
}
//----------------------------------------------------------------------------

//void TemperatureInfo::setSave(bool x)
//{
//    isSave = x;
//}
//----------------------------------------------------------------------------

void TemperatureInfo::setFileAdress(QString addres)
{
    fileAdress = addres;
}
//----------------------------------------------------------------------------
