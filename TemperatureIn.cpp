#include "TemperatureIn.h"
#include "ui_TemperatureIn.h"
//---------------------------------------------------------------
#include <QPalette>
#include <QDateTime>
#include <iostream>

#include <QDebug>

using namespace std;
//---------------------------------------------------------------

TemperatureIn::TemperatureIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperatureIn)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTemper()));
    timer->start(1000);
    tempeatureLabel = new QLabel(this);
    tempeatureLabel->setGeometry(10, 50, 120, 20);
}
//---------------------------------------------------------------

TemperatureIn::~TemperatureIn()
{
    delete ui;
}
//---------------------------------------------------------------

void TemperatureIn::updateTemper()
{
    QPalette pal = tempeatureLabel->palette();

    QTime time = QTime::currentTime();
    QString tempStr = time.toString("ss C");

    int sec = time.second();

    if(sec >= 0 && sec <=10 )
    {
        pal.setColor(QPalette::WindowText, Qt::blue);
    }
    else if(sec > 10 && sec <= 30)
    {
        pal.setColor(QPalette::WindowText, Qt::green);
    }
    else if( sec > 30)
    {
        pal.setColor(QPalette::WindowText, Qt::red);
    }

    tempeatureLabel->setPalette(pal);

    tempeatureLabel->setText(QString("%1 %2").arg("Температура: ").arg(tempStr));
}
//---------------------------------------------------------------
