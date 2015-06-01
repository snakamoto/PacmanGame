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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
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
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;
    QWidget *play_page;
    QWidget *gameover_page;
    QLabel *label_gameover;
    QScrollBar *horizontalScrollBar;
    QProgressBar *progressBar;
    QSlider *horizontalSlider;

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
        stackedWidget->setStyleSheet(QStringLiteral(""));
        stackedWidget->setFrameShadow(QFrame::Raised);
        stackedWidget->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        quitButton = new QPushButton(page);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(600, 550, 171, 39));
        quitButton->setStyleSheet(QStringLiteral(""));
        joinText = new QTextEdit(page);
        joinText->setObjectName(QStringLiteral("joinText"));
        joinText->setGeometry(QRect(270, 530, 111, 30));
        joinText->setMaximumSize(QSize(111, 30));
        joinText->setStyleSheet(QStringLiteral(""));
        singleplayerButton = new QPushButton(page);
        singleplayerButton->setObjectName(QStringLiteral("singleplayerButton"));
        singleplayerButton->setGeometry(QRect(30, 130, 171, 39));
        singleplayerButton->setStyleSheet(QStringLiteral(""));
        hostButton = new QPushButton(page);
        hostButton->setObjectName(QStringLiteral("hostButton"));
        hostButton->setGeometry(QRect(450, 490, 171, 39));
        hostButton->setStyleSheet(QStringLiteral(""));
        joinButton = new QPushButton(page);
        joinButton->setObjectName(QStringLiteral("joinButton"));
        joinButton->setGeometry(QRect(270, 490, 171, 39));
        joinButton->setStyleSheet(QStringLiteral(""));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(271, 51, 361, 24));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(271, 81, 361, 24));
        label_2->setFont(font);
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 110, 171, 20));
        plainTextEdit = new QPlainTextEdit(page);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(270, 120, 361, 371));
        plainTextEdit->setReadOnly(true);
        stackedWidget->addWidget(page);
        play_page = new QWidget();
        play_page->setObjectName(QStringLiteral("play_page"));
        play_page->setFocusPolicy(Qt::StrongFocus);
        stackedWidget->addWidget(play_page);
        gameover_page = new QWidget();
        gameover_page->setObjectName(QStringLiteral("gameover_page"));
        label_gameover = new QLabel(gameover_page);
        label_gameover->setObjectName(QStringLiteral("label_gameover"));
        label_gameover->setGeometry(QRect(370, 60, 121, 31));
        label_gameover->setFont(font);
        horizontalScrollBar = new QScrollBar(gameover_page);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(140, 210, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        progressBar = new QProgressBar(gameover_page);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(190, 290, 118, 23));
        progressBar->setValue(24);
        horizontalSlider = new QSlider(gameover_page);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(290, 150, 160, 19));
        horizontalSlider->setOrientation(Qt::Horizontal);
        stackedWidget->addWidget(gameover_page);
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
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">127.0.0.1</span></p></body></html>", 0));
        singleplayerButton->setText(QApplication::translate("MainMenu", "Play", 0));
        hostButton->setText(QApplication::translate("MainMenu", "Host", 0));
        joinButton->setText(QApplication::translate("MainMenu", "Join", 0));
        label->setText(QApplication::translate("MainMenu", "Game Over", 0));
        label_2->setText(QApplication::translate("MainMenu", "Score", 0));
        lineEdit->setText(QApplication::translate("MainMenu", "John", 0));
        label_gameover->setText(QApplication::translate("MainMenu", "Game Over", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
