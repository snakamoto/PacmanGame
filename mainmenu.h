#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <mainwindow.h>
#include "constants.h"
#include "highscorefile.h"
#include "highscore.h"
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
    void on_quitButton_clicked();

    void OnGameOver(int score);
    void OnGameConnected();

private:
    Ui::MainMenu *ui;
    MainWindow *window;
    HighScoreFile *hFile;
};

#endif // MAINMENU_H
