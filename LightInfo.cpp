#include "LightInfo.h"
#include "ui_LightInfo.h"

#include <QFile>
#include <QTextStream>
//----------------------------------------------------------------------------

LightInfo::LightInfo(QWidget *parent) :
    Device(parent),
    ui(new Ui::LightInfo)
{
    ui->setupUi(this);

    m_Timer = new QTimer(this);

    connect(m_Timer,          SIGNAL(timeout()),     this, SLOT(updateLightInfo()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteClick()));

    m_Timer->start(1000);
}
//----------------------------------------------------------------------------

LightInfo::~LightInfo()
{
    delete ui;
}
//----------------------------------------------------------------------------

void LightInfo::updateLightInfo()
{
    QPalette pal = ui->lightInfoLabel->palette();

    QTime time = QTime::currentTime();
    int t = time.hour();

    if(t >= 7 && t <= 21)
    {
        pal.setColor(QPalette::WindowText, Qt::black);
        ui->lightInfoLabel->setPalette(pal);
        ui->lightInfoLabel->setText("Switch OFF ");

        writeInFile("Switch OFF", CSV);
    }
    else
    {
        pal.setColor(QPalette::WindowText, Qt::red);
        ui->lightInfoLabel->setPalette(pal);
        ui->lightInfoLabel->setText("Switch ON ");

        writeInFile("Switch ON", CSV);
    }
}
//----------------------------------------------------------------------------

void LightInfo::deleteClick()
{
    emit deleteMe();
}
//----------------------------------------------------------------------------

QString LightInfo::nameSensor()
{
    return "lightInfo";
}
