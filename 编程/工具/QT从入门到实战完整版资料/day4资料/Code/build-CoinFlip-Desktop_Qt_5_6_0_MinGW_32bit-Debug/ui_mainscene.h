/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName(QStringLiteral("MainScene"));
        MainScene->resize(400, 300);
        actionQuit = new QAction(MainScene);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainScene);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainScene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainScene);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainScene->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QApplication::translate("MainScene", "MainScene", 0));
        actionQuit->setText(QApplication::translate("MainScene", "\351\200\200\345\207\272", 0));
        menu->setTitle(QApplication::translate("MainScene", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
