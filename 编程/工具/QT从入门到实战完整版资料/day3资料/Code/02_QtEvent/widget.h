#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //重写定时器的事件
    void timerEvent(QTimerEvent *);

    int id1; //定时器1的唯一标示
    int id2; //定时器2的唯一标示

    //重写事件过滤器的事件
    bool eventFilter(QObject *, QEvent *);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
