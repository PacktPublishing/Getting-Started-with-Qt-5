#include "mainwindow.h"


MainWindow::MainWindow()
{
    setWindowTitle("Form in Window");
    setFixedSize(500, 500);
    QPixmap newIcon("new.png");
    QPixmap openIcon("open.png");
    QPixmap closeIcon("close.png");

    // Setup File Menu
    fileMenu = menuBar()->addMenu("&File");
    quitAction = new QAction(closeIcon, "Quit", this);
    quitAction->setShortcuts(QKeySequence::Quit);

    newAction = new QAction(newIcon, "&New", this);
    newAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
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


    // Setup Tool bar menu
    toolbar = addToolBar("main toolbar");
    // toolbar->setMovable( false );

    newToolBarAction = toolbar->addAction(QIcon(newIcon), "New File");
    openToolBarAction = toolbar->addAction(QIcon(openIcon), "Open File");
    toolbar->addSeparator();
    closeToolBarAction = toolbar->addAction(QIcon(closeIcon), "Quit Application");


    // Setup Signals and Slots
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);
    connect(closeToolBarAction, &QAction::triggered, this, &QApplication::quit);


}


