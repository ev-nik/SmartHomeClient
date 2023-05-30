//----------------------------------
#ifndef WIDGET_H
#define WIDGET_H
//----------------------------------

#include <QWidget>
#include <QTimer>
#include <QDateTime>
//----------------------------------

namespace Ui { class Widget; }
//----------------------------------

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QTimer* timer;

private slots:
    void updateDateTime();
};
//-----------------------------------------------------------------------------------

#endif // WIDGET_H
