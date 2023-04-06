#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = 0);
    ~SmallWidget();

    //设置数字
    void setNum(int num);

    //获取数字
    int getNum();

private:
    Ui::SmallWidget *ui;
};

#endif // SMALLWIDGET_H
