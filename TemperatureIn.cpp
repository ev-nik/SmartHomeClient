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

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTemper()));
    timer->start(1000);
    tempeatureLabel = new QLabel(this);
    tempeatureLabel->setGeometry(10, 50, 80, 20);
}
//---------------------------------------------------------------

TemperatureIn::~TemperatureIn()
{
    delete ui;
}
//---------------------------------------------------------------

void TemperatureIn::updateTemper()
{
    QString tempIn = QDateTime::currentDateTime().toString("ss C");
    tempeatureLabel->setText(tempIn);
}
//---------------------------------------------------------------
