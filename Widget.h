#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <DateTimeInfo.h>
#include <TemperatureInfo.h>
#include <LightInfo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

//    void setSave(bool x);
    void setFileAdress(QString addres);

private:
    Ui::Widget *ui;

//    bool isSave;
    QString fileAdress;

private slots:
    void createDateTimeInfo();
    void createTemperatureInfo();
    void createLightInfo();
    void deleteDevice();
};
#endif // WIDGET_H
