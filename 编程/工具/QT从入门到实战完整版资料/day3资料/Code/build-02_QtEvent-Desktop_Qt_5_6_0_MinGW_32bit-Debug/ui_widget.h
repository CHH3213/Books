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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    myLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(462, 319);
        label = new myLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 271, 41));
        label->setFrameShape(QFrame::Box);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 90, 271, 41));
        label_2->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 160, 271, 41));
        label_3->setFrameShape(QFrame::WinPanel);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 220, 271, 41));
        label_4->setFrameShape(QFrame::Panel);
        label_4->setFrameShadow(QFrame::Sunken);
        btn = new QPushButton(Widget);
        btn->setObjectName(QStringLiteral("btn"));
        btn->setGeometry(QRect(340, 230, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        btn->setText(QApplication::translate("Widget", "\346\232\202\345\201\234", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
