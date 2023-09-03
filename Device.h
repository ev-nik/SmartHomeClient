#ifndef DEVICE_H
#define DEVICE_H
//----------------------------------------------------------------------------

#include <QWidget>
#include <QWidget>
#include <QFile>
#include <QTextStream>
//----------------------------------------------------------------------------

enum Formats
{
    TXT,
    CSV
};

namespace Ui {
class Device;
}

class Device : public QWidget
{
    Q_OBJECT

public:
    explicit Device(QWidget *parent = nullptr);
    ~Device();

public:
    void writeInFile(QString qs, Formats f);
    void setFileAdress(QString addres);
    virtual QString nameSensor() = 0;

private:
    QString path;

private:
    Ui::Device *ui;
};

#endif // DEVICE_H
//----------------------------------------------------------------------------


