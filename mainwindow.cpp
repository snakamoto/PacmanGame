#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, bool isHost, bool isSinglePlayer, QString connectTo) :
    QWidget(parent)
{
    if (isSinglePlayer)
    {
        createGame();
        return;
    }
    if(isHost)
    {
        server = new QTcpServer(this);
        server->listen(QHostAddress::Any,8888);

        qDebug() << "Starting server on any device port:8888";

        connect(server,SIGNAL(newConnection()),this, SLOT(onClientConnect()));
    }
    else
    {
        qDebug() << "Connecting to: " + connectTo;

        peerSocket = new QTcpSocket(this);
        peerSocket->connectToHost(QHostAddress(connectTo), 8888);
        connect(peerSocket,SIGNAL(connected()), this, SLOT(onConnected()));
    }
}

MainWindow::~MainWindow()
{
   delete ui;
   delete scene;
   delete view;
   delete updateTimer;
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

void MainWindow::onClientConnect()
{

    bool conAvailable = server->waitForNewConnection(100);
    peerSocket  = server->nextPendingConnection();
    peerConnection = new Connection(peerSocket);
    qDebug() << "Incoming connection received";
    createGame();
    scene->SetConnection(peerConnection);
    scene->SetPlayerAsHost();
}

void MainWindow::onConnected()
{
    qDebug() << "Local connection connecting to server";
    peerConnection = new Connection(peerSocket);
    qDebug() << "Connected to server";
    createGame();
    scene->SetConnection(peerConnection);
    scene->SetPlayerAsClient();
}

void MainWindow::CreateNewScene()
{
    scene->deleteLater();
    createGame();
}
