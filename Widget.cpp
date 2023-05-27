#include "Widget.h"
#include "ui_Widget.h"
//----------------------------------

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    time = new QTimer;

    time ->start(1000);
    connect(time, SIGNAL(timeout()), this, SLOT(currentDataTime()));
}
//-----------------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//-----------------------------------------------------------------------------------

void Widget::currentDataTime()
{
    QString dTime = QDateTime::currentDateTime().toString("hh:mm:ss dd.MM.yyyy"); // Текеущее время
                                                                                  // и дата в строку
    ui->currentTimeLable->setText(dTime);
}
//-----------------------------------------------------------------------------------

