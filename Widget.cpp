#include "Widget.h"
#include "ui_Widget.h"
//----------------------------------

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    dateTimeInfo  = new DateTimeInfo(this);
    temperatureIn = new TemperatureIn(this);
}
//-----------------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//-----------------------------------------------------------------------------------


