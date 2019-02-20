#include <QDateTime>
#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent){


    setWindowTitle("Locate Window");

    currentDateTimeLabel = new QLabel("Current Date and Time");
    currentDateTimeLabel->setAlignment(Qt::AlignCenter);


    setCentralWidget(currentDateTimeLabel);
    startTimer(1000);


}


void MainWindow::moveEvent(QMoveEvent *event) {
    int xCord = event->pos().x();
    int yCord = event->pos().y();

    QString text = QString::number(xCord) + ", " + QString::number(yCord);


    statusBar()->showMessage(text);

}


void MainWindow::timerEvent(QTimerEvent *event){
    Q_UNUSED(event);
    QString dateTime = QDateTime::currentDateTime().toString();
    currentDateTimeLabel->setText(dateTime);
}


