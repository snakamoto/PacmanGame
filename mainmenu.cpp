#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    // update the parent widget
    this->setGeometry(this->x()+32,this->y()+32,MAP_WIDTH, MAP_HEIGHT);
    //update stacked widget
    ui->stackedWidget->setGeometry(0,0,MAP_WIDTH, MAP_HEIGHT);
    ui->label->hide();
    ui->label_2->hide();

    hFile = new HighScoreFile("highscores.txt");

    // write high scores
    ui->plainTextEdit->clear();
    std::vector<Highscore> scores =  hFile->GetScores();
    for(int i = 0; i < scores.size(); i++)
    {
        Highscore sc = scores[i];
        ui->plainTextEdit->appendPlainText(QString::fromStdString(sc.user)+"\t"+ QString::number(sc.score));
    }


}
//connect(peerConnection, SIGNAL(OnPowerUpReceived(PowerUpStruct)), this, SLOT(on_sync_powerup_received(PowerUpStruct)));


MainMenu::~MainMenu()
{
    //window->deleteLater();
    delete ui;
}

void MainMenu::on_hostButton_clicked()
{
    // create a playable window
    window = new MainWindow(this, true, false, "");

    // connect Gameover
    connect(window, SIGNAL(ConnectedGame()), this, SLOT(OnGameConnected()));

    // let the widget begin at 0,0 with the correct height and width
    window->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);
    ui->stackedWidget->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);

    // add the current widget to the index 1
    ui->stackedWidget->insertWidget(1,window);

    // set index 1 of the stacked widgets to the host player
    ui->stackedWidget->setCurrentIndex(1);

    // show the current widget
    window->show();
}

void MainMenu::on_joinButton_clicked()
{
    // create a playable window
    window =new MainWindow(this, false, false, ui->joinText->toPlainText());

    connect(window, SIGNAL(ConnectedGame()), this, SLOT(OnGameConnected()));

    // let the widget begin at 0,0 with the correct height and width
    window->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);
    ui->stackedWidget->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);

    // add the current widget to the index 1
    ui->stackedWidget->insertWidget(1,window);

    // set index 1 of the stacked widgets to the client player
    ui->stackedWidget->setCurrentIndex(1);

    // show the current widget
    window->show();



}

void MainMenu::OnGameConnected()
{
    // connect Gameover
     connect(window->scene, SIGNAL(GameOver(int)),this, SLOT(OnGameOver(int)));
}

void MainMenu::on_singleplayerButton_clicked()
{
    // create a playable window
    window = new MainWindow(this, false, true, "");

    connect(window->scene, SIGNAL(GameOver(int)), this, SLOT(OnGameOver(int)));
    // let the widget begin at 0,0 with the correct height and width
    window->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);

    ui->stackedWidget->setGeometry(0,0, MAP_WIDTH, MAP_HEIGHT);

    // add the current widget to the index 1
    ui->stackedWidget->insertWidget(1, window);

    // set index 1 of the stacked widgets to the single player
    ui->stackedWidget->setCurrentIndex(1);

    // show the current widget
    window->show();

}

void MainMenu::on_quitButton_clicked()
{
    close();
}

void MainMenu::OnGameOver(int score)
{
   // go back to menu
   ui->stackedWidget->removeWidget(window);
   disconnect(window->scene, SIGNAL(GameOver(int)),this, SLOT(OnGameOver(int)));
   window->close();

   ui->stackedWidget->setCurrentIndex(0);
   ui->label->show();
   ui->label_2->show();
   ui->label_2->setText("Your score is " + QString::number(score));

   hFile->WriteHighscore(ui->lineEdit->text(), score);
   ui->plainTextEdit->clear();
   std::vector<Highscore> scores =  hFile->GetScores();
   for(int i = 0; i < scores.size(); i++)
   {
       Highscore sc = scores[i];
       ui->plainTextEdit->appendPlainText(QString::fromStdString(sc.user)+" "+ QString::number(sc.score));

   }

   //window->deleteLater();
}
