//----------------------------------
#ifndef WIDGET_H
#define WIDGET_H
//----------------------------------

#include <QWidget>
#include "DateTimeInfo.h"
#include "TemperatureIn.h"

namespace Ui { class Widget; }
//----------------------------------

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget* parent = 0);
    ~Widget();

private:
    Ui::Widget* ui;

private slots:
    void createTemperatureInfo();

    void createDateTimeInfo();

    void deleteDevice();

    void valueChanged(QString val);
    void valueChangedDT(QString val);
    void valueChangedW(QString val);

};
//-----------------------------------------------------------------------------------
#endif // WIDGET_H
