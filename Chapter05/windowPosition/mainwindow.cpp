#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent){


    setWindowTitle("Locate Window");

}


void MainWindow::moveEvent(QMoveEvent *event) {
    int xCord = event->pos().x();
    int yCord = event->pos().y();

    QString text = QString::number(xCord) + ", " + QString::number(yCord);


    statusBar()->showMessage(text);

}

