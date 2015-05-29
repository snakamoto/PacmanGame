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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *singleplayerButton;
    QPushButton *joinButton;
    QPushButton *hostButton;
    QTextEdit *joinText;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(800, 600);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 150, 321, 221));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        singleplayerButton = new QPushButton(widget);
        singleplayerButton->setObjectName(QStringLiteral("singleplayerButton"));

        verticalLayout->addWidget(singleplayerButton);

        joinButton = new QPushButton(widget);
        joinButton->setObjectName(QStringLiteral("joinButton"));

        verticalLayout->addWidget(joinButton);

        hostButton = new QPushButton(widget);
        hostButton->setObjectName(QStringLiteral("hostButton"));

        verticalLayout->addWidget(hostButton);


        horizontalLayout->addLayout(verticalLayout);

        joinText = new QTextEdit(widget);
        joinText->setObjectName(QStringLiteral("joinText"));
        joinText->setMaximumSize(QSize(111, 30));

        horizontalLayout->addWidget(joinText);

        MainMenu->setCentralWidget(centralwidget);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainWindow", 0));
        singleplayerButton->setText(QApplication::translate("MainMenu", "Play", 0));
        joinButton->setText(QApplication::translate("MainMenu", "Join", 0));
        hostButton->setText(QApplication::translate("MainMenu", "Host", 0));
        joinText->setHtml(QApplication::translate("MainMenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">255.255.255.255</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
