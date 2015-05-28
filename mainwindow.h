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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
      void OnUpdateTimer();

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
