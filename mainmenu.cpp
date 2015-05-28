#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_hostButton_clicked()
{
    MainWindow *window = new MainWindow(this, true, false, "");
    window->show();

}

void MainMenu::on_joinButton_clicked()
{
    MainWindow *window = new MainWindow(this, false, false, ui->joinText->toPlainText());
    window->show();
}

void MainMenu::on_singleplayerButton_clicked()
{
    MainWindow *window = new MainWindow(this, false, true, "");
    window->show();
}
