#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent){


    windowCentralWidget = new QWidget();
    mousePosition = new QLabel("Mouse Position");


    QVBoxLayout *innerLayout = new QVBoxLayout();
    innerLayout->addWidget(mousePosition);

    windowCentralWidget->setLayout(innerLayout);
    setCentralWidget(windowCentralWidget);
    statusBar()->showMessage("Ready");


    connect(this, SIGNAL(mouseMoved(QPoint)), this, SLOT(updateMousePosition(QPoint)));

}


void MainWindow::updateMousePosition(QPoint point){
    int xCord = point.x();
    int yCord = point.y();
    QString text = QString::number(xCord) + ", " + QString::number(yCord);
    mousePosition->setText(text);
    statusBar()->showMessage(text);


}


void MainWindow::mousePressEvent(QMouseEvent *event){
    emit mouseMoved(event->pos());
}