#include "Device.h"
#include "ui_Device.h"
//----------------------------------------------------------------------------

Device::Device(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Device)
{
    ui->setupUi(this);
}
//----------------------------------------------------------------------------

Device::~Device()
{
    delete ui;
}
//----------------------------------------------------------------------------

void Device::writeInFile(QString qs)
{
    if(path.isEmpty() == true)
    {
        return;
    }

    QFile file(path);

    if(file.open(QIODevice::Append) == false)
    {
        return;
    }

    QTextStream prog(&file); // С помощью такой конструкции
    prog << qs;  // передаем данные в файл

    file.close();
}
//----------------------------------------------------------------------------

void Device::setFileAdress( QString addres )
{
    path = addres;
}
//----------------------------------------------------------------------------
