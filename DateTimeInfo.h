#ifndef DATETIMEINFO_H
#define DATETIMEINFO_H
//----------------------------------------------------------------------------

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QTime>
#include <QFile>
#include <QString>
#include <QTextStream>

#include "Device.h"
//----------------------------------------------------------------------------

namespace Ui {
class DateTimeInfo;
}

class DateTimeInfo : public Device
{
    Q_OBJECT

public:
    explicit DateTimeInfo(QWidget *parent = nullptr);
    ~DateTimeInfo();

    QString nameSensor();

private:
    Ui::DateTimeInfo *ui;

    QTimer* m_Timer;

private slots:
    void tick();
    void deleteClick();

signals:
    void deleteMe();
};

#endif // DATETIMEINFO_H
