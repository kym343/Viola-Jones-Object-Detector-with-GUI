/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *pushButton;
    QCheckBox *checkBox_4;
    QPushButton *pushButton_3;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QLabel *label_8;
    QCheckBox *checkBox_5;
    QPushButton *pushButton_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testClass)
    {
        if (testClass->objectName().isEmpty())
            testClass->setObjectName(QStringLiteral("testClass"));
        testClass->resize(1287, 765);
        testClass->setStyleSheet(QStringLiteral("background: rgb(220, 220, 220)"));
        centralWidget = new QWidget(testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 1371, 861));
        groupBox_2->setLayoutDirection(Qt::LeftToRight);
        groupBox_2->setStyleSheet(QStringLiteral("background : rgb(220, 220, 220)"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 190, 191, 121));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral("background: rgb(212, 212, 212)"));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(50, 20, 131, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        checkBox->setFont(font1);
        checkBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        checkBox->setStyleSheet(QStringLiteral("color : rgb(255, 0, 0)"));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(50, 50, 131, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setStyleStrategy(QFont::PreferDefault);
        checkBox_2->setFont(font2);
        checkBox_2->setStyleSheet(QStringLiteral("color : rgb(0, 255, 0)"));
        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(50, 80, 131, 21));
        checkBox_3->setFont(font1);
        checkBox_3->setStyleSheet(QStringLiteral("color : rgb(0, 0, 255)"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 20, 71, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(930, 180, 320, 320));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setStyleSheet(QStringLiteral("background : rgb(0, 0, 0)"));
        label_4->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 70, 71, 31));
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(130, 390, 71, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        spinBox->setFont(font4);
        spinBox->setStyleSheet(QStringLiteral("background: rgb(212, 212, 212)"));
        spinBox->setMaximum(100);
        spinBox->setSingleStep(1);
        spinBox->setDisplayIntegerBase(10);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(850, 70, 31, 31));
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(240, 630, 641, 61));
        listWidget->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 130, 640, 480));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QStringLiteral("background : rgb(0, 0, 0)"));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(850, 20, 31, 31));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(930, 140, 151, 21));
        checkBox_4->setFont(font1);
        checkBox_4->setContextMenuPolicy(Qt::DefaultContextMenu);
        checkBox_4->setStyleSheet(QStringLiteral("color : rgb(84, 84, 84)"));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 530, 141, 51));
        pushButton_3->setFont(font4);
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 390, 61, 31));
        label_7->setFont(font3);
        label_7->setStyleSheet(QStringLiteral("background : rgb(220, 220, 220)"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 20, 581, 31));
        label_2->setFont(font4);
        label_2->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 70, 581, 31));
        label_3->setFont(font4);
        label_3->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(980, 20, 261, 101));
        textBrowser->setFont(font);
        textBrowser->setFrameShape(QFrame::StyledPanel);
        textBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser->setLineWidth(0);
        textBrowser->setMidLineWidth(0);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1100, 570, 151, 41));
        label_8->setFont(font4);
        label_8->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(930, 520, 151, 31));
        checkBox_5->setFont(font1);
        checkBox_5->setContextMenuPolicy(Qt::DefaultContextMenu);
        checkBox_5->setStyleSheet(QStringLiteral("color : rgb(84, 84, 84)"));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1200, 520, 51, 31));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        pushButton_4->setFont(font5);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1100, 630, 151, 41));
        label_9->setFont(font4);
        label_9->setStyleSheet(QStringLiteral("background: rgb(198, 198, 198)"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(960, 560, 121, 51));
        QFont font6;
        font6.setFamily(QStringLiteral("Arial"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        label_10->setFont(font6);
        label_10->setStyleSheet(QStringLiteral("color : rgb(255, 0, 0)"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(960, 620, 121, 51));
        label_11->setFont(font6);
        label_11->setStyleSheet(QStringLiteral("color : rgb(0, 0, 255)"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        testClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1287, 26));
        testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testClass->setStatusBar(statusBar);

        retranslateUi(testClass);
        QObject::connect(pushButton_3, SIGNAL(clicked()), testClass, SLOT(slotDisplay()));
        QObject::connect(pushButton, SIGNAL(clicked()), testClass, SLOT(selectInputDir()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), testClass, SLOT(selectOutputDir()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), testClass, SLOT(Evaluation()));

        QMetaObject::connectSlotsByName(testClass);
    } // setupUi

    void retranslateUi(QMainWindow *testClass)
    {
        testClass->setWindowTitle(QApplication::translate("testClass", "test", 0));
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QApplication::translate("testClass", "Cheack box", 0));
        checkBox->setText(QApplication::translate("testClass", "Face", 0));
        checkBox_2->setText(QApplication::translate("testClass", "Human", 0));
        checkBox_3->setText(QApplication::translate("testClass", "Car", 0));
        label_5->setText(QApplication::translate("testClass", "Input :", 0));
        label_4->setText(QString());
        label_6->setText(QApplication::translate("testClass", "Output :", 0));
        pushButton_2->setText(QApplication::translate("testClass", "...", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("testClass", "...", 0));
        checkBox_4->setText(QApplication::translate("testClass", "Display Box", 0));
        pushButton_3->setText(QApplication::translate("testClass", "Start", 0));
        label_7->setText(QApplication::translate("testClass", "Delay :", 0));
        label_2->setText(QApplication::translate("testClass", "C:/", 0));
        label_3->setText(QApplication::translate("testClass", "C:/", 0));
        textBrowser->setHtml(QApplication::translate("testClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:20pt; font-weight:600; color:#ff0000;\">Team 2</span></p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim';\"><br /></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-weight:600;\">\352\260\225\354\230\201\353\254\265, \352\271\200\353\217"
                        "\231\354\232\261, \353\260\225\355\230\225\352\267\274, \354\234\244\353\257\274\354\204\261</span></p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim';\"><br /></p></body></html>", 0));
        label_8->setText(QString());
        checkBox_5->setText(QApplication::translate("testClass", "Evaluation", 0));
        pushButton_4->setText(QApplication::translate("testClass", "Add", 0));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("testClass", "Precision", 0));
        label_11->setText(QApplication::translate("testClass", "Recall", 0));
    } // retranslateUi

};

namespace Ui {
    class testClass: public Ui_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
