#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <DateTimeInfo.h>
#include <TemperatureInfo.h>
#include <LightInfo.h>
#include <QDebug>

#include "Device.h"
#include "LeakInfo.h"
//----------------------------------------------------------------------------

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setFileAdress(QString addres);
    void setDeleteFile(bool x);

private:
    Ui::Widget *ui;

    QString path;
    bool del;

private slots:
    void createDateTimeInfo();
    void createTemperatureInfo();
    void createLightInfo();
    void createLeakInfo();
    void deleteDevice();
};
#endif // WIDGET_H
