#ifndef TEMPERATUREIN_H
#define TEMPERATUREIN_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

namespace Ui {
    class TemperatureIn;
}

class TemperatureIn : public QWidget
{
    Q_OBJECT

public:
    explicit TemperatureIn(QWidget *parent = 0);
    ~TemperatureIn();

private:
    Ui::TemperatureIn *ui;

    QLabel *tempeatureLabel;
    QTimer *timer;

private slots:
    void updateTemper();
};

#endif // TEMPERATUREIN_H
