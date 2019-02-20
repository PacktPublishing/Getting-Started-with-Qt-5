#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QMoveEvent>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QDebug>
#include <QDateTime>
#include <QMainWindow>
#include <QStatusBar>
#include "dragTextEdit.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);


    private slots:
        void updateStatusBar();

private:
        DragTextEdit *slateDragTextEdit;

};
#endif