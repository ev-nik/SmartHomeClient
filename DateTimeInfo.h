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

//----------------------------------------------------------------------------

namespace Ui {
class DateTimeInfo;
}

class DateTimeInfo : public QWidget
{
    Q_OBJECT

public:
    explicit DateTimeInfo(QWidget *parent = nullptr);
    ~DateTimeInfo();

//    void setSave(bool x);

    void setFileAdress(QString addres);

private:
    Ui::DateTimeInfo *ui;

    QTimer* m_Timer;

//    bool isSave;

    void writeInFile(QString qs);

    QString fileAdress;

private slots:
    void tick();
    void deleteClick();
    void updateWeekDay();

signals:
    void deleteMe();
};

#endif // DATETIMEINFO_H
