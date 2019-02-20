#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle("SRM System");
    setFixedSize(500, 500);
    QPixmap newIcon("new.png");
    QPixmap openIcon("open.png");
    QPixmap closeIcon("close.png");

    // Setup File Menu
    fileMenu = menuBar()->addMenu("&File");
    quitAction = new QAction(closeIcon, "Quit", this);
    quitAction->setShortcuts(QKeySequence::Quit);

    newAction = new QAction(newIcon, "&New", this);
    newAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    openAction = new QAction(openIcon, "&Open", this);
    openAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));


    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);


    helpMenu = menuBar()->addMenu("Help");
    aboutAction = new QAction("About", this);
    aboutAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));

    helpMenu->addAction(aboutAction);

    // Setup Signals and Slots
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);


}


