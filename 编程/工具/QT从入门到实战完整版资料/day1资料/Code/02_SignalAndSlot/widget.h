#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "teacher.h"
#include "student.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    Teacher * zt;
    Student * st;

    void classIsOver();

};

#endif // WIDGET_H
