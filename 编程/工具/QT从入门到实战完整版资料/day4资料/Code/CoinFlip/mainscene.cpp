#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });


    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move( this->width() * 0.5 - startBtn->width() * 0.5 ,this->height() * 0.7 );

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;


    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        chooseScene->hide(); //将选择关卡场景 隐藏掉
        this->show(); //重新显示主场景
    });

    connect(startBtn,&MyPushButton::clicked,[=](){
        //qDebug() << "点击了开始";
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();


        //延时进入到选择关卡场景中
        QTimer::singleShot(500,this,[=](){
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });


    });
}


void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    pix.load(":/res/Title.png");

    pix = pix.scaled( pix.width() * 0.5 , pix.height() * 0.5);

    painter.drawPixmap(10,30,pix);


}

MainScene::~MainScene()
{
    delete ui;
}
