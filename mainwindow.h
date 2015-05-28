#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpServer>
#include <connection.h>
#include <QMainWindow>
#include "pacgraphicsscene.h"
#include <QElapsedTimer>
#include <QTimer>


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, bool isHost=true, bool isSinglePlayer=true, QString connectTo="");
    ~MainWindow();

private slots:
      void OnUpdateTimer();
      void onClientConnect(); //client connected to server (we)
      void onConnected(); // client (we) connected to server

private:
    Ui::MainWindow *ui;
    void createGame();

    QTcpServer *server;

    QTcpSocket *peerSocket;
    Connection *peerConnection;
    QTimer *updateTimer; //Hack to update
    QElapsedTimer elapsedTimer;

    QGraphicsView *view;
    PacGraphicsScene *scene; //Our scene

};

#endif // MAINWINDOW_H
