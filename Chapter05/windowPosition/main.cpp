#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    MainWindow window;
    window.resize(300, 300);
    window.show();

    return app.exec();

}