#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
       createGame();
}

MainWindow::~MainWindow()
{


}


void MainWindow::createGame()
{

    updateTimer = new QTimer(this);
    view = new QGraphicsView(this);


    scene = new PacGraphicsScene(0,0,TILES_X * WIDTH,TILES_Y * WIDTH,view);
    view->setScene(scene);
    qDebug() << "Setting size";
    this->setGeometry(400,400,1024,768);
    view->setGeometry(0,0,this->width()-280,this->height());
    view->show();

   connect(updateTimer,SIGNAL(timeout()),this,SLOT(OnUpdateTimer()));
   updateTimer->start(1);
   elapsedTimer.start();
}

void MainWindow::OnUpdateTimer()
{

    qint64 nSec;

    nSec = elapsedTimer.nsecsElapsed();

    float elapsed_seconds = (double)nSec / 1000000000.0f;

    scene->Update(elapsed_seconds);

    elapsedTimer.restart();
}
