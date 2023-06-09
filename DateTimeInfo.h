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
    explicit DateTimeInfo(QWidget *parent = 0);
    ~DateTimeInfo();

private:
    Ui::DateTimeInfo *ui;

    QLabel *dateTimeLabel;
    QLabel *dayOfWeekLabel;

    QTimer *timer;

private slots:

    void tick();
    void updateWeekDay();

};

#endif // DATETIMEINFO_H
