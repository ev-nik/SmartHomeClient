#include "TemperatureIn.h"
#include "ui_TemperatureIn.h"
//---------------------------------------------------------------

#include <QDateTime>
//---------------------------------------------------------------

TemperatureIn::TemperatureIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperatureIn)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(temper()));
    timer->start(1000);
    tempeatureLabel = new QLabel(this);
}
//---------------------------------------------------------------

TemperatureIn::~TemperatureIn()
{
    delete ui;
}
//---------------------------------------------------------------

void TemperatureIn::temper()
{
    tempeatureLabel->setGeometry(10, 50, 80, 20);
    QString tempIn = QDateTime::currentDateTime().toString("ss C");
    tempeatureLabel->setText(tempIn);
}
//---------------------------------------------------------------
