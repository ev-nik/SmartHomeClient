#include "TemperatureIn.h"
#include "ui_TemperatureIn.h"
//---------------------------------------------------------------

#include <QPalette>
#include <QDateTime>
#include <iostream>
#include <QDebug>
#include <QVBoxLayout>

using namespace std;
//---------------------------------------------------------------

TemperatureIn::TemperatureIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperatureIn)
{
    ui->setupUi(this);

    m_Timer = new QTimer(this);

    connect(m_Timer, SIGNAL(timeout()), this, SLOT(updateTemper()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteClick()));

    m_Timer->start(1000);
}
//---------------------------------------------------------------

TemperatureIn::~TemperatureIn()
{
    delete ui;
}
//---------------------------------------------------------------

void TemperatureIn::updateTemper()
{
    QPalette pal = ui->temperatureLabel->palette();

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

    ui->temperatureLabel->setPalette(pal);

    ui->temperatureLabel->setText(QString("%1 %2").arg("Температура: ").arg(tempStr));

    emit changed(tempStr);
}
//---------------------------------------------------------------

void TemperatureIn::deleteClick()
{
    emit deleteMe();  // Испускание собственного сигнала( к этому сигналу
                      // можно подключиться из вне)
}
//---------------------------------------------------------------
