#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMoveEvent>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QDebug>
#include <QDateTime>
#include <QStatusBar>

#include <QLabel>

class MainWindow: public QMainWindow
{

    Q_OBJECT
    public slots:
        void updateMousePosition(QPoint pos);

    signals:
        void mouseMoved(QPoint pos);

    public:
        MainWindow(QWidget *parent = 0);

    protected:
        void mousePressEvent(QMouseEvent *event);

    private:
        QLabel *mousePosition;
        QWidget *windowCentralWidget;

};


#endif