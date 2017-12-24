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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
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
    QLabel *label;
    QLabel *label_2;
    QSpinBox *bright;
    QDoubleSpinBox *contrast;
    QPushButton *setButton;
    XVideoWidget *des;
    QPushButton *exportButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QLabel *label_3;
    QComboBox *rotate;
    QLabel *label_4;
    QComboBox *flip;
    QLabel *label_5;
    QSpinBox *width;
    QSpinBox *height;
    QSpinBox *pyup;
    QSpinBox *pydown;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *cx;
    QSpinBox *cy;
    QSpinBox *cw;
    QSpinBox *ch;

    void setupUi(QWidget *XVideoUIClass)
    {
        if (XVideoUIClass->objectName().isEmpty())
            XVideoUIClass->setObjectName(QStringLiteral("XVideoUIClass"));
        XVideoUIClass->resize(1204, 815);
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
"}\n"
"QLabel\n"
"{\n"
"font: 75 12pt \"\351\273\221\344\275\223"
                        "\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"#playButton{background-color: rgba(255, 255, 255,0);}\n"
"\n"
"#playButton:hover{image: url(:/XVideoUI/Resources/PlayN.png);}\n"
"\n"
"#playButton:!hover{image: url(:/XVideoUI/Resources/PlayH.png);}\n"
"\n"
"#playButton:pressed{image: url(:/XVideoUI/Resources/PlayP.png);}\n"
"\n"
"#pauseButton{background-color: rgba(255, 255, 255,0);}\n"
"\n"
"#pauseButton:hover{image: url(:/XVideoUI/Resources/PauseN.png);}\n"
"\n"
"#pauseButton:!hover{image: url(:/XVideoUI/Resources/PauseH.png);}\n"
"\n"
"#pauseButton:pressed{image: url(:/XVideoUI/Resources/PauseP.png);}"));
        closeButton = new QPushButton(XVideoUIClass);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(1170, 10, 31, 21));
        closeButton->setStyleSheet(QStringLiteral(""));
        closeButton->setFlat(true);
        src1Video = new XVideoWidget(XVideoUIClass);
        src1Video->setObjectName(QStringLiteral("src1Video"));
        src1Video->setGeometry(QRect(10, 20, 560, 452));
        openButton = new QPushButton(XVideoUIClass);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(630, 490, 93, 31));
        playSlider = new QSlider(XVideoUIClass);
        playSlider->setObjectName(QStringLiteral("playSlider"));
        playSlider->setGeometry(QRect(10, 500, 561, 22));
        playSlider->setMaximum(999);
        playSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(XVideoUIClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 550, 121, 21));
        label_2 = new QLabel(XVideoUIClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 580, 161, 20));
        bright = new QSpinBox(XVideoUIClass);
        bright->setObjectName(QStringLiteral("bright"));
        bright->setGeometry(QRect(740, 550, 81, 22));
        contrast = new QDoubleSpinBox(XVideoUIClass);
        contrast->setObjectName(QStringLiteral("contrast"));
        contrast->setGeometry(QRect(740, 580, 81, 22));
        contrast->setMaximum(3);
        contrast->setValue(1);
        setButton = new QPushButton(XVideoUIClass);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(940, 550, 93, 41));
        des = new XVideoWidget(XVideoUIClass);
        des->setObjectName(QStringLiteral("des"));
        des->setGeometry(QRect(590, 20, 560, 452));
        exportButton = new QPushButton(XVideoUIClass);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        exportButton->setGeometry(QRect(760, 490, 93, 31));
        playButton = new QPushButton(XVideoUIClass);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(220, 540, 51, 51));
        pauseButton = new QPushButton(XVideoUIClass);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(280, 540, 51, 51));
        label_3 = new QLabel(XVideoUIClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(630, 610, 81, 21));
        rotate = new QComboBox(XVideoUIClass);
        rotate->setObjectName(QStringLiteral("rotate"));
        rotate->setGeometry(QRect(740, 610, 87, 22));
        label_4 = new QLabel(XVideoUIClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(630, 650, 81, 21));
        flip = new QComboBox(XVideoUIClass);
        flip->setObjectName(QStringLiteral("flip"));
        flip->setGeometry(QRect(740, 650, 87, 22));
        label_5 = new QLabel(XVideoUIClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(590, 700, 121, 21));
        width = new QSpinBox(XVideoUIClass);
        width->setObjectName(QStringLiteral("width"));
        width->setGeometry(QRect(730, 700, 121, 22));
        width->setMaximum(9999);
        height = new QSpinBox(XVideoUIClass);
        height->setObjectName(QStringLiteral("height"));
        height->setGeometry(QRect(850, 700, 121, 22));
        height->setMaximum(99999);
        pyup = new QSpinBox(XVideoUIClass);
        pyup->setObjectName(QStringLiteral("pyup"));
        pyup->setGeometry(QRect(850, 740, 121, 22));
        pyup->setMaximum(100);
        pyup->setValue(0);
        pydown = new QSpinBox(XVideoUIClass);
        pydown->setObjectName(QStringLiteral("pydown"));
        pydown->setGeometry(QRect(730, 740, 121, 22));
        pydown->setMaximum(100);
        label_6 = new QLabel(XVideoUIClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(440, 740, 271, 21));
        label_7 = new QLabel(XVideoUIClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(440, 780, 271, 21));
        cx = new QSpinBox(XVideoUIClass);
        cx->setObjectName(QStringLiteral("cx"));
        cx->setGeometry(QRect(730, 780, 61, 22));
        cx->setMaximum(9999);
        cy = new QSpinBox(XVideoUIClass);
        cy->setObjectName(QStringLiteral("cy"));
        cy->setGeometry(QRect(790, 780, 61, 22));
        cy->setMaximum(9999);
        cw = new QSpinBox(XVideoUIClass);
        cw->setObjectName(QStringLiteral("cw"));
        cw->setGeometry(QRect(850, 780, 61, 22));
        cw->setMaximum(9999);
        ch = new QSpinBox(XVideoUIClass);
        ch->setObjectName(QStringLiteral("ch"));
        ch->setGeometry(QRect(910, 780, 61, 22));
        ch->setMaximum(9999);

        retranslateUi(XVideoUIClass);
        QObject::connect(closeButton, SIGNAL(clicked()), XVideoUIClass, SLOT(close()));
        QObject::connect(openButton, SIGNAL(clicked()), XVideoUIClass, SLOT(open()));
        QObject::connect(playSlider, SIGNAL(sliderPressed()), XVideoUIClass, SLOT(sliderPress()));
        QObject::connect(playSlider, SIGNAL(sliderReleased()), XVideoUIClass, SLOT(sliderRelease()));
        QObject::connect(playSlider, SIGNAL(sliderMoved(int)), XVideoUIClass, SLOT(setPos(int)));
        QObject::connect(setButton, SIGNAL(clicked()), XVideoUIClass, SLOT(set()));
        QObject::connect(exportButton, SIGNAL(clicked()), XVideoUIClass, SLOT(exportVideo()));
        QObject::connect(playButton, SIGNAL(clicked()), XVideoUIClass, SLOT(play()));
        QObject::connect(pauseButton, SIGNAL(clicked()), XVideoUIClass, SLOT(pause()));

        QMetaObject::connectSlotsByName(XVideoUIClass);
    } // setupUi

    void retranslateUi(QWidget *XVideoUIClass)
    {
        XVideoUIClass->setWindowTitle(QApplication::translate("XVideoUIClass", "XVideoUI", Q_NULLPTR));
        closeButton->setText(QApplication::translate("XVideoUIClass", "X", Q_NULLPTR));
        openButton->setText(QApplication::translate("XVideoUIClass", "\346\211\223\345\274\200", Q_NULLPTR));
        label->setText(QApplication::translate("XVideoUIClass", "\344\272\256\345\272\246[0-100]", Q_NULLPTR));
        label_2->setText(QApplication::translate("XVideoUIClass", "\345\257\271\346\257\224\345\272\246[1.0-3.0]", Q_NULLPTR));
        setButton->setText(QApplication::translate("XVideoUIClass", "\350\256\276\347\275\256", Q_NULLPTR));
        exportButton->setText(QApplication::translate("XVideoUIClass", "\345\257\274\345\207\272", Q_NULLPTR));
        playButton->setText(QString());
        pauseButton->setText(QString());
        label_3->setText(QApplication::translate("XVideoUIClass", "\345\233\276\345\203\217\346\227\213\350\275\254", Q_NULLPTR));
        rotate->clear();
        rotate->insertItems(0, QStringList()
         << QApplication::translate("XVideoUIClass", "0", Q_NULLPTR)
         << QApplication::translate("XVideoUIClass", "90", Q_NULLPTR)
         << QApplication::translate("XVideoUIClass", "180", Q_NULLPTR)
         << QApplication::translate("XVideoUIClass", "270", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("XVideoUIClass", "\345\233\276\345\203\217\351\225\234\345\203\217", Q_NULLPTR));
        flip->clear();
        flip->insertItems(0, QStringList()
         << QApplication::translate("XVideoUIClass", "\344\270\215\345\244\204\347\220\206", Q_NULLPTR)
         << QApplication::translate("XVideoUIClass", "\344\270\212\344\270\213\351\225\234\345\203\217", Q_NULLPTR)
         << QApplication::translate("XVideoUIClass", "\345\267\246\345\217\263\351\225\234\345\203\217", Q_NULLPTR)
         << QApplication::translate("XVideoUIClass", "\344\270\212\344\270\213\345\267\246\345\217\263\351\225\234\345\203\217", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("XVideoUIClass", "\345\233\276\345\203\217\345\260\272\345\257\270W,H", Q_NULLPTR));
        label_6->setText(QApplication::translate("XVideoUIClass", "\345\233\276\345\203\217\351\207\221\345\255\227\345\241\224\357\274\210\351\253\230\346\226\257\357\274\214\346\213\211\346\231\256\346\213\211\346\226\257\357\274\211", Q_NULLPTR));
        label_7->setText(QApplication::translate("XVideoUIClass", "\345\233\276\345\203\217\350\243\201\345\211\252(x,y,width,height)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class XVideoUIClass: public Ui_XVideoUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XVIDEOUI_H
