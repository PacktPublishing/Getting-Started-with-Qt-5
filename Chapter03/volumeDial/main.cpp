#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QDial>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); 
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *volumeLabel = new QLabel("0");
    QDial *volumeDial= new QDial;

    layout->addWidget(volumeDial);
    layout->addWidget(volumeLabel);
    QObject::connect(volumeDial, SIGNAL(valueChanged(int)), volumeLabel, SLOT(setNum(int)));
    window->setLayout(layout);
    window->show();
    return app.exec();



}
