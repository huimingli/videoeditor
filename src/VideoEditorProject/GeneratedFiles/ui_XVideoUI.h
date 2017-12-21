/********************************************************************************
** Form generated from reading UI file 'XVideoUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XVIDEOUI_H
#define UI_XVIDEOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "xvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_XVideoUIClass
{
public:
    QPushButton *closeButton;
    XVideoWidget *src1Video;
    QPushButton *openButton;
    QSlider *playSlider;

    void setupUi(QWidget *XVideoUIClass)
    {
        if (XVideoUIClass->objectName().isEmpty())
            XVideoUIClass->setObjectName(QStringLiteral("XVideoUIClass"));
        XVideoUIClass->resize(1118, 815);
        XVideoUIClass->setStyleSheet(QString::fromUtf8("#XVideoUIClass\n"
"{\n"
"background-color: rgb(53, 53, 53);\n"
"}\n"
"\n"
"#closeButton\n"
"{\n"
"font: 75 11pt \"\347\255\211\347\272\277\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(53, 53, 53);\n"
"}\n"
"QPushButton:!hover\n"
"{\n"
"    background-color: qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 rgba(120, 120, 120, 255),stop:0.495      rgba(39, 39, 39, 255),stop:0.505 rgba(39, 39, 39, 255),stop:1 rgba(120, 120, 120, 255));\n"
"    border:none;\n"
"    border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 75 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 rgba(39, 39, 39, 255),stop:0.495      rgba(120, 120, 120, 255),stop:0.505 rgba(120, 120, 120, 255),stop:1 rgba(39, 39, 39, 255));\n"
"    border:none;\n"
"    border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 75 12pt \"\351\273\221\344\275\223\";\n"
"}"));
        closeButton = new QPushButton(XVideoUIClass);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(1070, 10, 31, 21));
        closeButton->setStyleSheet(QStringLiteral(""));
        closeButton->setFlat(true);
        src1Video = new XVideoWidget(XVideoUIClass);
        src1Video->setObjectName(QStringLiteral("src1Video"));
        src1Video->setGeometry(QRect(10, 20, 800, 600));
        openButton = new QPushButton(XVideoUIClass);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(840, 620, 93, 31));
        playSlider = new QSlider(XVideoUIClass);
        playSlider->setObjectName(QStringLiteral("playSlider"));
        playSlider->setGeometry(QRect(10, 640, 801, 22));
        playSlider->setMaximum(999);
        playSlider->setOrientation(Qt::Horizontal);

        retranslateUi(XVideoUIClass);
        QObject::connect(closeButton, SIGNAL(clicked()), XVideoUIClass, SLOT(close()));
        QObject::connect(openButton, SIGNAL(clicked()), XVideoUIClass, SLOT(open()));
        QObject::connect(playSlider, SIGNAL(sliderPressed()), XVideoUIClass, SLOT(sliderPress()));
        QObject::connect(playSlider, SIGNAL(sliderReleased()), XVideoUIClass, SLOT(sliderRelease()));
        QObject::connect(playSlider, SIGNAL(sliderMoved(int)), XVideoUIClass, SLOT(setPos(int)));

        QMetaObject::connectSlotsByName(XVideoUIClass);
    } // setupUi

    void retranslateUi(QWidget *XVideoUIClass)
    {
        XVideoUIClass->setWindowTitle(QApplication::translate("XVideoUIClass", "XVideoUI", Q_NULLPTR));
        closeButton->setText(QApplication::translate("XVideoUIClass", "X", Q_NULLPTR));
        openButton->setText(QApplication::translate("XVideoUIClass", "\346\211\223\345\274\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class XVideoUIClass: public Ui_XVideoUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XVIDEOUI_H
