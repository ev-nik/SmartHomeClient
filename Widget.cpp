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

    QVBoxLayout* vLayout = new QVBoxLayout( this ); // Объект с помощью которого можно компановать
                                                    // объекты по вертикали

    vLayout->setSpacing( 0 );            // Расстояние между виджетами внутри слоя

    vLayout->addWidget(m_DateTimeInfo);  // Добавить виджет на слой

    vLayout->addStretch();               // Пружинка

    connect(ui->createTemperatureInfoButton, SIGNAL(clicked(bool)), this, SLOT(createTemperatureInfo()));
}
//-----------------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//-----------------------------------------------------------------------------------

void Widget::createTemperatureInfo()
{
    m_TemperatureIn = new TemperatureIn(this);

    QLayout* l = layout();
    l->addWidget(m_TemperatureIn);
}
