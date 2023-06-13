#include "Widget.h"
#include "ui_Widget.h"

#include <QVBoxLayout>
//----------------------------------

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_DateTimeInfo  = new DateTimeInfo(this);
    m_TemperatureIn = new TemperatureIn(this);

    QVBoxLayout* vLayout = new QVBoxLayout( this ); // Объект с помощью которого можно компановать
                                                    // объекты по вертикали

    vLayout->setSpacing( 0 );            // Расстояние между виджетами внутри слоя

    vLayout->addWidget(m_DateTimeInfo);  // Добавить виджет на слой
    vLayout->addWidget(m_TemperatureIn); //-----------------------
    vLayout->addStretch();               // Пружинка
}
//-----------------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//-----------------------------------------------------------------------------------
