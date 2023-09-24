#include "Device.h"
#include "ui_Device.h"

#include <QDateTime>
#include <QDebug>
#include <string>
#include <algorithm>
//----------------------------------------------------------------------------

Device::Device(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Device)
{
    ui->setupUi(this);

//   setFileAdress(path);

}
//----------------------------------------------------------------------------

Device::~Device()
{
    delete ui;
}
//----------------------------------------------------------------------------

void Device::writeInFile(QString qs, Formats f)
{
    if(path.isEmpty())
    {
        return;
    }

    QString ext;

    if(f == TXT)
    {
        ext = ".txt";
    }
    else if(f == CSV)
    {
        ext = ".csv";
    }

    QString filePath = path + "/" + nameSensor() + ext;

    QFile file(filePath);

    if(file.open(QIODevice::Append) == false)
    {
        qWarning() << Q_FUNC_INFO << "Failed open file: " << filePath; // Лог об ошибке
        return;
    }

    QTextStream prog(&file); // С помощью такой конструкции
                             // передаем данные в файл
    if(f == CSV)
    {
        QString dateTime = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
        prog << dateTime << ";" << qs << ";\n";
    }

    else
    {
        prog << qs << "\n";
    }

    file.close();
}
//----------------------------------------------------------------------------

void Device::setFileAdress( QString addres )
{
    path = addres;
}
//----------------------------------------------------------------------------

