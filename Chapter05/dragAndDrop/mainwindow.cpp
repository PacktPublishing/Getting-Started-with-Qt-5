#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent)
{

    QWidget *mainWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    slateDragTextEdit = new DragTextEdit();

    layout->addWidget(slateDragTextEdit);


    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);


    statusBar()->showMessage(QString::number(0));

    connect(slateDragTextEdit, SIGNAL(textChanged()), this, SLOT(updateStatusBar()));
}


void MainWindow::updateStatusBar()
{
    int charCount = slateDragTextEdit->toPlainText().count();
    statusBar()->showMessage(QString::number(charCount));

}

