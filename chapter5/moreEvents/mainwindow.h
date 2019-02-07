#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMoveEvent>
#include <QMainWindow>
#include <QStatusBar>
#include <QLabel>


class MainWindow: public QMainWindow {

    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);

    protected:
        void moveEvent(QMoveEvent *event);
        void timerEvent(QTimerEvent *event);


    private:
        QLabel *currentDateTimeLabel;


};


#endif
