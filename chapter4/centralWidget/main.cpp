#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar); //fix for menubar notshowing in ubuntu
    MainWindow mainwindow;
    
    mainwindow.show();
    return app.exec();

}
