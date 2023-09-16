#include "Widget.h"
#include "ui_Widget.h"
//----------------------------------------------------------------------------

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QIcon iconTemp = QIcon(":/therm.png");
    ui->createTemperatureButton->setIcon(iconTemp);

    QIcon iconLight = QIcon(":/light.png");
    ui->createLightInfoButton->setIcon(iconLight);

    QIcon iconWeek = QIcon(":/week.png");
    ui->createDateTimeInfoButton->setIcon(iconWeek);

    QVBoxLayout* vLayoute = new QVBoxLayout(this);
    vLayoute->setSpacing(0);
    vLayoute->addStretch();

    connect(ui->createDateTimeInfoButton, SIGNAL(clicked(bool)), this, SLOT(createDateTimeInfo()));
    connect(ui->createTemperatureButton,  SIGNAL(clicked(bool)), this, SLOT(createTemperatureInfo()));
    connect(ui->createLightInfoButton,    SIGNAL(clicked(bool)), this, SLOT(createLightInfo()));
    connect(ui->createLeakInfoButton,     SIGNAL(clicked(bool)), this, SLOT(createLeakInfo()));
}
//----------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//----------------------------------------------------------------------------

void Widget::createDateTimeInfo()
{
    DateTimeInfo* dateTimeInfo = new DateTimeInfo(this);

    dateTimeInfo->setFileAdress(path);

    if(del)
    {
        QFile::remove(path + "/" + dateTimeInfo->nameSensor() + ".csv");
    }

    ui->createDateTimeInfoButton->setEnabled(false);

    connect(dateTimeInfo, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(dateTimeInfo);
}
//----------------------------------------------------------------------------

void Widget::createTemperatureInfo()
{
    TemperatureInfo* temperatureInfo = new TemperatureInfo(this);

    temperatureInfo->setFileAdress(path);

    if(del)
    {
        QFile::remove(path + "/" + temperatureInfo->nameSensor() + ".csv");
    }

    ui->createTemperatureButton->setEnabled(false);

    connect(temperatureInfo, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(temperatureInfo);
}
//----------------------------------------------------------------------------

void Widget::createLightInfo()
{
    LightInfo* lightInfo = new LightInfo(this);

    lightInfo->setFileAdress(path);

    if(del)
    {
        QFile::remove(path + "/" + lightInfo->nameSensor() + ".csv");
    }

    ui->createLightInfoButton->setEnabled(false);

    connect(lightInfo, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(lightInfo);
}
//----------------------------------------------------------------------------

void Widget::createLeakInfo()
{
    LeakInfo* leakInfo = new LeakInfo(this);

    leakInfo->setFileAdress(path);

    if(del)
    {
        QFile::remove(path + "/" + leakInfo->nameSensor() + ".csv");
    }

    ui->createLeakInfoButton->setEnabled(false);

    connect(leakInfo, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(leakInfo);
}

//----------------------------------------------------------------------------

void Widget::deleteDevice()
{
    QObject* device = sender();

    DateTimeInfo   * dTInfo = qobject_cast<DateTimeInfo   *>(device);
    TemperatureInfo* tInfo  = qobject_cast<TemperatureInfo*>(device);
    LightInfo      * lInfo  = qobject_cast<LightInfo      *>(device);
    LeakInfo       * leInfo = qobject_cast<LeakInfo       *>(device);

    if( dTInfo != nullptr )
    {
        ui->createDateTimeInfoButton->setEnabled(true);
    }
    else if(tInfo != nullptr)
    {
        ui->createTemperatureButton->setEnabled(true);
    }
    else if( lInfo != nullptr)
    {
        ui->createLightInfoButton->setEnabled(true);
    }
    else if(leInfo != nullptr)
    {
        ui->createLeakInfoButton->setEnabled(true);
    }

    delete device;
}
//----------------------------------------------------------------------------

void Widget::setFileAdress(QString filePath)
{
    while(filePath[filePath.size() - 1] == '/')
    {
        filePath.chop(1);
    }

    path = filePath;
}
//----------------------------------------------------------------------------

void Widget::setDeleteFile(bool x)
{
    del = x;
}
