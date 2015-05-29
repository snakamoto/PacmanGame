#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    // update the parent widget
    this->setGeometry(this->x()+32,this->y()+32,MAP_WIDTH, MAP_HEIGHT);
}

MainMenu::~MainMenu()
{
    delete window;
    delete ui;
}

void MainMenu::on_hostButton_clicked()
{
    // create a playable window
    window =new MainWindow(this, true, false, "");

    // let the widget begin at 0,0 with the correct height and width
    window->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);
    ui->stackedWidget->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);

    // add the current widget to the index 1
    ui->stackedWidget->insertWidget(1,window);

    // set index 1 of the stacked widgets to the host player
    ui->stackedWidget->setCurrentIndex(1);

    // show the current widget
    window->show();

    // set the focus of the current widget
    ui->stackedWidget->setFocus();
    window->setFocus();

}

void MainMenu::on_joinButton_clicked()
{
    // create a playable window
    window =new MainWindow(this, false, false, ui->joinText->toPlainText());

    // let the widget begin at 0,0 with the correct height and width
    window->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);
    ui->stackedWidget->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);

    // add the current widget to the index 1
    ui->stackedWidget->insertWidget(1,window);

    // set index 1 of the stacked widgets to the client player
    ui->stackedWidget->setCurrentIndex(1);

    // show the current widget
    window->show();

    // set the focus of the current widget
    ui->stackedWidget->setFocus();
    window->setFocus();
}

void MainMenu::on_singleplayerButton_clicked()
{
    // create a playable window
    window = new MainWindow(this, false, true, "");

    // let the widget begin at 0,0 with the correct height and width
    window->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);
    ui->stackedWidget->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);

    // add the current widget to the index 1
    ui->stackedWidget->insertWidget(1,window);

    // set index 1 of the stacked widgets to the single player
    ui->stackedWidget->setCurrentIndex(1);

    // show the current widget
    window->show();

    // set the focus of the current widget
    ui->stackedWidget->setFocus();
    window->setFocus();
}
