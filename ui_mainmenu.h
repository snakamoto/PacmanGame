/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *quitButton;
    QTextEdit *joinText;
    QPushButton *singleplayerButton;
    QPushButton *hostButton;
    QPushButton *joinButton;
    QWidget *play_page;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(800, 600);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 791, 601));
        stackedWidget->setFocusPolicy(Qt::StrongFocus);
        stackedWidget->setStyleSheet(QLatin1String("\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #f5f9ff,\n"
"                stop :   0.5 #c7dfff, stop :   0.55 #afd2ff, stop :   1.0 #c0dbff);\n"
"        color: #006aff;\n"
"        font: bold large \"Arial\";\n"
"        height: 30px;"));
        stackedWidget->setFrameShadow(QFrame::Raised);
        stackedWidget->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        quitButton = new QPushButton(page);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(30, 260, 171, 39));
        quitButton->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #ffd9aa,\n"
"                stop :   0.5 #ffbb6e, stop :   0.55 #feae42, stop :   1.0 #fedb74);\n"
"}\n"
"\n"
"QPushButton {\n"
"        border: 1px solid #6593cf;\n"
"        border-radius: 2px;\n"
"        padding: 5px 15px 2px 5px;\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #f5f9ff,\n"
"                stop :   0.5 #c7dfff, stop :   0.55 #afd2ff, stop :   1.0 #c0dbff);\n"
"        color: #006aff;\n"
"        font: bold large \"Arial\";\n"
"        height: 30px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #c0dbff,\n"
"        stop :   0.5 #cfd26f, stop :   0.55 #c7df6f, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton:on {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, "
                        "stop :   0.0 #5AA72D,\n"
"        stop :   0.5 #B3E296, stop :   0.55 #B3E296, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        background: transparent #e5e9ee;\n"
"        padding-top: 2px;        \n"
"        padding-left: 3px;\n"
"        color: black;\n"
"}"));
        joinText = new QTextEdit(page);
        joinText->setObjectName(QStringLiteral("joinText"));
        joinText->setGeometry(QRect(60, 220, 111, 30));
        joinText->setMaximumSize(QSize(111, 30));
        joinText->setStyleSheet(QLatin1String(" border: 1px solid #6593cf;\n"
"        border-radius: 2px;\n"
"        padding: 5px 15px 2px 5px;\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #f5f9ff,\n"
"                stop :   0.5 #c7dfff, stop :   0.55 #afd2ff, stop :   1.0 #c0dbff);\n"
"        color: #006aff;\n"
"        font: bold large \"Arial\";\n"
"        height: 30px;"));
        singleplayerButton = new QPushButton(page);
        singleplayerButton->setObjectName(QStringLiteral("singleplayerButton"));
        singleplayerButton->setGeometry(QRect(30, 70, 171, 39));
        singleplayerButton->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #ffd9aa,\n"
"                stop :   0.5 #ffbb6e, stop :   0.55 #feae42, stop :   1.0 #fedb74);\n"
"}\n"
"\n"
"QPushButton {\n"
"        border: 1px solid #6593cf;\n"
"        border-radius: 2px;\n"
"        padding: 5px 15px 2px 5px;\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #f5f9ff,\n"
"                stop :   0.5 #c7dfff, stop :   0.55 #afd2ff, stop :   1.0 #c0dbff);\n"
"        color: #006aff;\n"
"        font: bold large \"Arial\";\n"
"        height: 30px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #c0dbff,\n"
"        stop :   0.5 #cfd26f, stop :   0.55 #c7df6f, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton:on {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, "
                        "stop :   0.0 #5AA72D,\n"
"        stop :   0.5 #B3E296, stop :   0.55 #B3E296, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        background: transparent #e5e9ee;\n"
"        padding-top: 2px;        \n"
"        padding-left: 3px;\n"
"        color: black;\n"
"}"));
        hostButton = new QPushButton(page);
        hostButton->setObjectName(QStringLiteral("hostButton"));
        hostButton->setGeometry(QRect(30, 120, 171, 39));
        hostButton->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #ffd9aa,\n"
"                stop :   0.5 #ffbb6e, stop :   0.55 #feae42, stop :   1.0 #fedb74);\n"
"}\n"
"\n"
"QPushButton {\n"
"        border: 1px solid #6593cf;\n"
"        border-radius: 2px;\n"
"        padding: 5px 15px 2px 5px;\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #f5f9ff,\n"
"                stop :   0.5 #c7dfff, stop :   0.55 #afd2ff, stop :   1.0 #c0dbff);\n"
"        color: #006aff;\n"
"        font: bold large \"Arial\";\n"
"        height: 30px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #c0dbff,\n"
"        stop :   0.5 #cfd26f, stop :   0.55 #c7df6f, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton:on {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, "
                        "stop :   0.0 #5AA72D,\n"
"        stop :   0.5 #B3E296, stop :   0.55 #B3E296, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        background: transparent #e5e9ee;\n"
"        padding-top: 2px;        \n"
"        padding-left: 3px;\n"
"        color: black;\n"
"}"));
        joinButton = new QPushButton(page);
        joinButton->setObjectName(QStringLiteral("joinButton"));
        joinButton->setGeometry(QRect(30, 170, 171, 39));
        joinButton->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #ffd9aa,\n"
"                stop :   0.5 #ffbb6e, stop :   0.55 #feae42, stop :   1.0 #fedb74);\n"
"}\n"
"\n"
"QPushButton {\n"
"        border: 1px solid #6593cf;\n"
"        border-radius: 2px;\n"
"        padding: 5px 15px 2px 5px;\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #f5f9ff,\n"
"                stop :   0.5 #c7dfff, stop :   0.55 #afd2ff, stop :   1.0 #c0dbff);\n"
"        color: #006aff;\n"
"        font: bold large \"Arial\";\n"
"        height: 30px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #c0dbff,\n"
"        stop :   0.5 #cfd26f, stop :   0.55 #c7df6f, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton:on {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, "
                        "stop :   0.0 #5AA72D,\n"
"        stop :   0.5 #B3E296, stop :   0.55 #B3E296, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        background: transparent #e5e9ee;\n"
"        padding-top: 2px;        \n"
"        padding-left: 3px;\n"
"        color: black;\n"
"}"));
        stackedWidget->addWidget(page);
        play_page = new QWidget();
        play_page->setObjectName(QStringLiteral("play_page"));
        play_page->setFocusPolicy(Qt::StrongFocus);
        stackedWidget->addWidget(play_page);
        MainMenu->setCentralWidget(centralwidget);

        retranslateUi(MainMenu);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainWindow", 0));
        quitButton->setText(QApplication::translate("MainMenu", "Quit", 0));
        joinText->setHtml(QApplication::translate("MainMenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:8.25pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">127.0.0.1</span></p></body></html>", 0));
        singleplayerButton->setText(QApplication::translate("MainMenu", "Play", 0));
        hostButton->setText(QApplication::translate("MainMenu", "Host", 0));
        joinButton->setText(QApplication::translate("MainMenu", "Join", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
