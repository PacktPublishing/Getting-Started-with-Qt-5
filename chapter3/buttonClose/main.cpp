#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton *quitButton = new QPushButton("Quit");

    QObject::connect(quitButton, SIGNAL(clicked()),
            &app, SLOT(quit()));
    quitButton->show();
    return app.exec();
}



