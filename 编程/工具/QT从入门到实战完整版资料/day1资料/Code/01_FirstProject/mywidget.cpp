#include "mywidget.h"
#include <QPushButton> //按钮控件的头文件
#include "mypushbutton.h"
#include <QDebug>
// 命名规范
// 类名 首字母大写，单词和单词之间首字母大写
// 函数名 变量名称 首字母小写，单词和单词之间首字母大写

//快捷键
//注释  ctrl + /
//运行  ctrl + r
//编译  ctrl + b
//字体缩放 ctrl + 鼠标滚轮
//查找  ctrl + f
//整行移动 ctrl + shift + ↑ 或者↓
//帮助文档 F1
//自动对齐  ctrl + i;
//同名之间的.h 和 .cpp切换  F4

//帮助文档 第一种方式 F1  第二种 左侧按钮  第三种 C:\Qt\Qt5.6.0\5.6\mingw49_32\bin

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    //btn->show(); //show以顶层方式弹出窗口控件
    //让btn对象 依赖在 myWidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");


    //创建第二个按钮 按照控件的大小创建窗口
    QPushButton * btn2 = new QPushButton("第二个按钮",this);

    //移动btn2按钮
    btn2->move(100,100);

    //按钮可不可以 重新制定大小 可以！
    btn2->resize(50,50);

    //重置窗口大小
    resize(600,400);

    //设置固定窗口大小
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("第一个窗口");





    //创建一个自己的按钮对象
    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");

    myBtn->move(200,0);
    myBtn->setParent(this); //设置到对象树中



    //需求  点击我的按钮 关闭窗口
    //参数1  信号的发送者 参数2  发送的信号（函数的地址） 参数3  信号的接受者 参数4  处理的槽函数
    //connect( myBtn, &MyPushButton::clicked, this, &myWidget::close  );
    connect( myBtn, &QPushButton::clicked, this, &QWidget::close  );
}

myWidget::~myWidget()
{
    qDebug() << "myWidget的析构调用";
}
