#include "Widget.h"
#include "ui_Widget.h"

#include <QVBoxLayout>
#include <QDebug>
//----------------------------------

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout* vLayout = new QVBoxLayout( this ); // Объект с помощью которого можно компановать
                                                    // объекты по вертикали

    vLayout->setSpacing( 0 );            // Расстояние между виджетами внутри слоя

    vLayout->addStretch();               // Пружинка

    connect(ui->createTemperatureInfoButton, SIGNAL(clicked(bool)), this, SLOT(createTemperatureInfo()));
    connect(ui->createDateTimeInfoButton,    SIGNAL(clicked(bool)), this, SLOT(createDateTimeInfo()));
}
//-----------------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//-----------------------------------------------------------------------------------

void Widget::createTemperatureInfo()
{
    TemperatureIn* temperatureIn = new TemperatureIn(this);
    connect(temperatureIn, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(temperatureIn);
}
//-----------------------------------------------------------------------------------

void Widget::deleteDevice()
{
    QObject* device = sender(); // sender() здесь возвращает указатель на того кто испустил сигнал

    delete device; // удаляем датчик (здесь device и есть указатель на наш датчик)
}
//-----------------------------------------------------------------------------------

void Widget::createDateTimeInfo()
{
    DateTimeInfo* dateTimeInfo = new DateTimeInfo(this);
    connect(dateTimeInfo, SIGNAL(deleteMe()), this, SLOT(deleteDevice()));

    QLayout* l = layout();
    l->addWidget(dateTimeInfo);
}
//-----------------------------------------------------------------------------------
