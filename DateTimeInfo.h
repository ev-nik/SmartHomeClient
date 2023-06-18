#ifndef DATETIMEINFO_H
#define DATETIMEINFO_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

namespace Ui {
    class DateTimeInfo;
}

class DateTimeInfo : public QWidget
{
    Q_OBJECT

public:
    explicit DateTimeInfo(QWidget* parent = 0);
    ~DateTimeInfo();

private:
    Ui::DateTimeInfo* ui;

    QTimer* m_Timer;

private slots:
    void tick();
    void updateWeekDay();
    void deleteClick();

signals:
    void deleteMe();
    void changedDT(QString val);
    void changedW(QString val);
};

#endif // DATETIMEINFO_H
