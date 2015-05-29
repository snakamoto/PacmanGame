#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <mainwindow.h>
#include "constants.h"
namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_hostButton_clicked();

    void on_joinButton_clicked();

    void on_singleplayerButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
