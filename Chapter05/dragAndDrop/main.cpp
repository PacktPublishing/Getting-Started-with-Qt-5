#include <QApplication>
#include <Qt>

#include "mainwindow.h"


int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Drag Text Edit");
    window.show();

    return app.exec();

}