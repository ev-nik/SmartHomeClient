#ifndef TEMPERATUREINFO_H
#define TEMPERATUREINFO_H

#include <QWidget>
#include <QTimer>
#include <QTime>

namespace Ui {
class TemperatureInfo;
}

class TemperatureInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TemperatureInfo(QWidget *parent = nullptr);
    ~TemperatureInfo();

//    void setSave(bool x);

    void setFileAdress(QString addres);

private:
    Ui::TemperatureInfo *ui;

    QTimer* m_Timer;

    void writeInFile(int temp);

//    bool isSave;

    QString fileAdress;

private slots:
    void updateTemperature();
    int temperature();
    void deleteClick();

signals:
    void deleteMe();
};

#endif // TEMPERATUREINFO_H
