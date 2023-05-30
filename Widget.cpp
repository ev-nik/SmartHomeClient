#include "Widget.h"
#include "ui_Widget.h"
//----------------------------------

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer ->start(10);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateDateTime()));
}
//-----------------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//-----------------------------------------------------------------------------------

void Widget::updateDateTime()
{
    QString dTime = QDateTime::currentDateTime().toString("hh:mm:ss.zzz dd.MM.yyyy"); // Текеущее время
                                                                                      // и дата в строку
    ui->dateTimeLabel->setText(dTime);
}
//-----------------------------------------------------------------------------------

