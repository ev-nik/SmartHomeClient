#ifndef LEAKINFO_H
#define LEAKINFO_H
//----------------------------------------------------------------------------

#include <QWidget>
#include <QTimer>
#include <QTime>

#include "Device.h"
//----------------------------------------------------------------------------

namespace Ui {
class LeakInfo;
}

class LeakInfo : public Device
{
    Q_OBJECT

public:
    explicit LeakInfo(QString path, QWidget *parent = nullptr);
    ~LeakInfo();

    virtual QString nameSensor();

private:
    Ui::LeakInfo *ui;

    QTimer* m_Timer;

private slots:
    void updateLeakInfo();
    void deleteClick();

signals:
    void deleteMe();
};

#endif // LEAKINFO_H
