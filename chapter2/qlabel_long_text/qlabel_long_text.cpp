#include <QApplication>
#include <QString>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString message = "‘What do you know about this business?’ the King said to Alice.\n‘Nothing,’ said Alice.\n‘Nothing whatever?’ persisted the King.\n‘Nothing whatever,’ said Alice.";
    QLabel label(message);
    label.setFont(QFont("Comic Sans MS", 18));
    label.setAlignment(Qt::AlignCenter);

    label.show();

    return app.exec();
}
