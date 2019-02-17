#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle("Form in Window");
    setFixedSize(500, 500);

    createIcons();
    setupCoreWidgets();
    createMenuBar();
    createToolBar();

    centralWidgetLayout->addLayout(formLayout);
    centralWidgetLayout->addWidget(appTable);
    centralWidgetLayout->addLayout(buttonsLayout);

    mainWidget->setLayout(centralWidgetLayout);

    setCentralWidget(mainWidget);

    setupSignalsAndSlots();


}

void MainWindow::setupSignalsAndSlots() {

    // Setup Signals and Slots
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);
    connect(closeToolBarAction, &QAction::triggered, this, &QApplication::quit);

    connect(savePushButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));

}

void MainWindow::createIcons() {
     newIcon = QPixmap("new.png");
     openIcon = QPixmap("open.png");
     closeIcon = QPixmap("close.png");
     clearIcon = QPixmap("clear.png");
}


void MainWindow::setupCoreWidgets() {
    mainWidget = new QWidget();
    centralWidgetLayout = new QVBoxLayout();
    formLayout = new QGridLayout();
    buttonsLayout = new QHBoxLayout();

    nameLabel = new QLabel("Name:");
    dateOfBirthLabel= new QLabel("Date Of Birth:");
    phoneNumberLabel = new QLabel("Phone Number");
    savePushButton = new QPushButton("Save");
    newPushButton = new QPushButton("Clear All");

    nameLineEdit = new QLineEdit();
    dateOfBirthEdit = new QDateEdit(QDate::currentDate());
    phoneNumberLineEdit = new QLineEdit();



    // TableView
    appTable = new QTableView();
    model = new QStandardItemModel(1, 3, this);
    appTable->setContextMenuPolicy(Qt::CustomContextMenu);
    appTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); /** Note **/


    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Date of Birth")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Phone Number")));

    appTable->setModel(model);
    QStandardItem *firstItem = new QStandardItem(QString("G. Shone"));
    QDate dateOfBirth(1980, 1, 1);
    QStandardItem *secondItem = new QStandardItem(dateOfBirth.toString());
    QStandardItem *thirdItem = new QStandardItem(QString("05443394858"));
    model->setItem(0,0,firstItem);
    model->setItem(0,1,secondItem);
    model->setItem(0,2,thirdItem);

    formLayout->addWidget(nameLabel, 0, 0);
    formLayout->addWidget(nameLineEdit, 0, 1);
    formLayout->addWidget(dateOfBirthLabel, 1, 0);
    formLayout->addWidget(dateOfBirthEdit, 1, 1);
    formLayout->addWidget(phoneNumberLabel, 2, 0);
    formLayout->addWidget(phoneNumberLineEdit, 2, 1);


    buttonsLayout->addStretch();
    buttonsLayout->addWidget(savePushButton);
    buttonsLayout->addWidget(newPushButton);

}

void MainWindow::createToolBar() {
    // Setup Tool bar menu
    toolbar = addToolBar("main toolbar");
    // toolbar->setMovable( false );

    newToolBarAction = toolbar->addAction(QIcon(newIcon), "New File");
    openToolBarAction = toolbar->addAction(QIcon(openIcon), "Open File");
    toolbar->addSeparator();
    clearToolBarAction = toolbar->addAction(QIcon(clearIcon), "Clear All");
    closeToolBarAction = toolbar->addAction(QIcon(closeIcon), "Quit Application");


}

void MainWindow::createMenuBar() {
    // Setup File Menu
    fileMenu = menuBar()->addMenu("&File");
    quitAction = new QAction(closeIcon, "Quit", this);
    quitAction->setShortcuts(QKeySequence::Quit);

    newAction = new QAction(newIcon, "&New", this);
    newAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    openAction = new QAction(openIcon, "&New", this);
    openAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));


    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);


    helpMenu = menuBar()->addMenu("Help");
    aboutAction = new QAction("About", this);
    aboutAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));

    helpMenu->addAction(aboutAction);

}


void MainWindow::saveButtonClicked()
{
    QStandardItem *name = new QStandardItem(nameLineEdit->text());
    QStandardItem *dob = new QStandardItem(dateOfBirthEdit->date().toString());
    QStandardItem *phoneNumber = new QStandardItem(phoneNumberLineEdit->text());

    model->appendRow({ name, dob, phoneNumber});
    clearFields();


}

void MainWindow::clearFields()
{
    nameLineEdit->clear();
    phoneNumberLineEdit->setText("");
    QDate dateOfBirth(1980, 1, 1);
    dateOfBirthEdit->setDate(dateOfBirth);


}


