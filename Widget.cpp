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

    connect(dateTimeInfo, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(dateTimeInfo);


}
//----------------------------------------------------------------------------

void Widget::createTemperatureInfo()
{
    TemperatureInfo* temperatureInfo = new TemperatureInfo(this);

    temperatureInfo->setFileAdress(path);

    connect(temperatureInfo, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(temperatureInfo);
}
//----------------------------------------------------------------------------

void Widget::createLightInfo()
{
    LightInfo* lightInfo = new LightInfo(this);

    lightInfo->setFileAdress(path);

    connect(lightInfo, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(lightInfo);
}
//----------------------------------------------------------------------------

void Widget::deleteDevice()
{
    QObject* device = sender();

    delete device;
}
//----------------------------------------------------------------------------

void Widget::setFileAdress(QString addres)
{
    path = addres;
}

