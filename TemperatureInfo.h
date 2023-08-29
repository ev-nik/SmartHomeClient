#ifndef TEMPERATUREINFO_H
#define TEMPERATUREINFO_H

#include <QWidget>
#include <QTimer>
#include <QTime>

#include "Device.h"

namespace Ui {
class TemperatureInfo;
}

class TemperatureInfo : public Device
{
    Q_OBJECT

public:
    explicit TemperatureInfo(QWidget *parent = nullptr);
    ~TemperatureInfo();

private:
    Ui::TemperatureInfo *ui;

    QTimer* m_Timer;

private slots:
    void updateTemperature();
    int  temperature();
    void deleteClick();

signals:
    void deleteMe();
};

#endif // TEMPERATUREINFO_H
