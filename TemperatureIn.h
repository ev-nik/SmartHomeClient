#ifndef TEMPERATUREIN_H
#define TEMPERATUREIN_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QPalette>

namespace Ui {
    class TemperatureIn;
}

class TemperatureIn : public QWidget
{
    Q_OBJECT

public:
    explicit TemperatureIn(QWidget* parent = 0);
    ~TemperatureIn();

private:
    Ui::TemperatureIn* ui;

    QTimer* m_Timer;

private slots:

    void updateTemper();
    void deleteClick();

signals:
    void deleteMe();

};

#endif // TEMPERATUREIN_H
