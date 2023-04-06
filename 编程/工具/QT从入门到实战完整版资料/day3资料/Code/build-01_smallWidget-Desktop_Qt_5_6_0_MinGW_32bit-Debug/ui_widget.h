/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <smallwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    SmallWidget *widget;
    QPushButton *btn_get;
    QPushButton *btn_set;
    SmallWidget *widget_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(470, 356);
        widget = new SmallWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 40, 231, 41));
        btn_get = new QPushButton(Widget);
        btn_get->setObjectName(QStringLiteral("btn_get"));
        btn_get->setGeometry(QRect(170, 140, 75, 23));
        btn_set = new QPushButton(Widget);
        btn_set->setObjectName(QStringLiteral("btn_set"));
        btn_set->setGeometry(QRect(170, 200, 75, 23));
        widget_2 = new SmallWidget(Widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(60, 230, 341, 80));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        btn_get->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\345\275\223\345\211\215\345\200\274", 0));
        btn_set->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\345\210\260\344\270\200\345\215\212", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
