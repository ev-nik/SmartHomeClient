#ifndef LIGHTINFO_H
#define LIGHTINFO_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QString>

#include "Device.h"

namespace Ui {
class LightInfo;
}

class LightInfo : public Device
{
    Q_OBJECT

public:
    explicit LightInfo(QWidget *parent = nullptr);
    ~LightInfo();

    QString nameSensor();

private:
    Ui::LightInfo *ui;

    QTimer* m_Timer;

private slots:
    void updateLightInfo();
    void deleteClick();

signals:
    void deleteMe();
};

#endif // LIGHTINFO_H
