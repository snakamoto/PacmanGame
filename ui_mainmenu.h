/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QPushButton *hostButton;
    QPushButton *joinButton;
    QTextEdit *joinText;
    QPushButton *singleplayerButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(800, 600);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        hostButton = new QPushButton(centralwidget);
        hostButton->setObjectName(QStringLiteral("hostButton"));
        hostButton->setGeometry(QRect(180, 80, 75, 23));
        joinButton = new QPushButton(centralwidget);
        joinButton->setObjectName(QStringLiteral("joinButton"));
        joinButton->setGeometry(QRect(290, 210, 75, 23));
        joinText = new QTextEdit(centralwidget);
        joinText->setObjectName(QStringLiteral("joinText"));
        joinText->setGeometry(QRect(103, 210, 161, 31));
        singleplayerButton = new QPushButton(centralwidget);
        singleplayerButton->setObjectName(QStringLiteral("singleplayerButton"));
        singleplayerButton->setGeometry(QRect(220, 370, 75, 23));
        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainWindow", 0));
        hostButton->setText(QApplication::translate("MainMenu", "Host", 0));
        joinButton->setText(QApplication::translate("MainMenu", "PushButton", 0));
        joinText->setHtml(QApplication::translate("MainMenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">127.0.0.1</span></p></body></html>", 0));
        singleplayerButton->setText(QApplication::translate("MainMenu", "Solo queue", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
