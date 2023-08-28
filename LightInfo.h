#ifndef LIGHTINFO_H
#define LIGHTINFO_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QString>

namespace Ui {
class LightInfo;
}

class LightInfo : public QWidget
{
    Q_OBJECT

public:
    explicit LightInfo(QWidget *parent = nullptr);
    ~LightInfo();

//    void setSave(bool x);

    void setFileAdress(QString addres);

private:
    Ui::LightInfo *ui;

    QTimer* m_Timer;

//    bool isSave;

    void writeInFile(QString qs);

    QString fileAdress;

private slots:
    void updateLightInfo();
    void deleteClick();

signals:
    void deleteMe();
};

#endif // LIGHTINFO_H
