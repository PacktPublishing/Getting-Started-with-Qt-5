#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton myButton(QIcon("filesaveas.png"),"Push Me");
    myButton.setToolTip("Click this to turn back the hands of time");
    myButton.show();
    return app.exec();

}
    
