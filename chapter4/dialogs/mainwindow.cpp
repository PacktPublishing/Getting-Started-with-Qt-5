#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle("RMS System");
    setFixedSize(500, 500);

    setWindowIcon(QIcon("window_logo.png"));

    createIcons();
    setupCoreWidgets();
    createMenuBar();
    createToolBar();

    centralWidgetLayout->addLayout(formLayout);
    centralWidgetLayout->addWidget(appTable);
    //centralWidgetLayout->addStretch();
    centralWidgetLayout->addLayout(buttonsLayout);

    mainWidget->setLayout(centralWidgetLayout);

    setCentralWidget(mainWidget);

    setupSignalsAndSlots();

}



void MainWindow::createIcons() {
    newIcon = QPixmap("new.png");
    openIcon = QPixmap("open.png");
    closeIcon = QPixmap("close.png");
    clearIcon = QPixmap("clear.png");
    deleteIcon = QPixmap("delete.png");
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
    clearPushButton = new QPushButton("Clear All");

    nameLineEdit = new QLineEdit();
    dateOfBirthEdit = new QDateEdit(QDate(1980, 1, 1));
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
    QStandardItem *firstItem = new QStandardItem(QString("G. Sohne"));
    QDate dateOfBirth(1980, 1, 1);
    QStandardItem *secondItem = new QStandardItem(dateOfBirth.toString());
    QStandardItem *thirdItem = new QStandardItem(QString("05443394858"));
    model->setItem(0,0,firstItem);
    model->setItem(0,1,secondItem);
    model->setItem(0,2,thirdItem);


    //Layouts
    formLayout->addWidget(nameLabel, 0, 0);
    formLayout->addWidget(nameLineEdit, 0, 1);
    formLayout->addWidget(dateOfBirthLabel, 1, 0);
    formLayout->addWidget(dateOfBirthEdit, 1, 1);
    formLayout->addWidget(phoneNumberLabel, 2, 0);
    formLayout->addWidget(phoneNumberLineEdit, 2, 1);


    buttonsLayout->addStretch();
    buttonsLayout->addWidget(savePushButton);
    buttonsLayout->addWidget(clearPushButton);

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


void MainWindow::createToolBar() {
    // Setup Tool bar menu
    toolbar = addToolBar("main toolbar");
    // toolbar->setMovable( false );

    newToolBarAction = toolbar->addAction(QIcon(newIcon), "New File");
    openToolBarAction = toolbar->addAction(QIcon(openIcon), "Open File");
    toolbar->addSeparator();
    clearToolBarAction = toolbar->addAction(QIcon(clearIcon), "Clear All");
    deleteOneEntryToolBarAction = toolbar->addAction(QIcon(deleteIcon), "Delete a record");
    closeToolBarAction = toolbar->addAction(QIcon(closeIcon), "Quit Application");

}


void MainWindow::setupSignalsAndSlots() {
    // Setup Signals and Slots
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutDialog()));
    connect(clearToolBarAction, SIGNAL(triggered()), this, SLOT(clearAllRecords()));
    connect(closeToolBarAction, &QAction::triggered, this, &QApplication::quit);
    connect(deleteOneEntryToolBarAction, SIGNAL(triggered()), this, SLOT(deleteSavedRecord()));
    connect(savePushButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
    connect(clearPushButton, SIGNAL(clicked()), this, SLOT(clearAllRecords()));
}

void MainWindow::deleteSavedRecord()
{

    bool ok;
    int rowId = QInputDialog::getInt(this, tr("Select Row to delete"),
                                        tr("Please enter Row ID of record (Eg. 1)"),
                                        1, 1, model->rowCount(), 1, &ok );
    if (ok)
    {
        model->removeRow(rowId-1);
    }

}



void MainWindow::saveButtonClicked()
{

    QStandardItem *name = new QStandardItem(nameLineEdit->text());
    QStandardItem *dob = new QStandardItem(dateOfBirthEdit->date().toString());
    QStandardItem *phoneNumber = new QStandardItem(phoneNumberLineEdit->text());

    model->appendRow({ name, dob, phoneNumber});
    clearFields();

    QMessageBox::information(this, tr("RMS System"), tr("Record saved successfully!"),
                             QMessageBox::Ok|QMessageBox::Default,
                             QMessageBox::NoButton, QMessageBox::NoButton);


}

void MainWindow::clearFields()
{
    nameLineEdit->clear();
    phoneNumberLineEdit->setText("");
    QDate dateOfBirth(1980, 1, 1);
    dateOfBirthEdit->setDate(dateOfBirth);


}


void MainWindow::clearAllRecords()
{
    /*
    int status = QMessageBox::question( this, tr("Delete Records ?"),
                                        tr("You are about to delete all saved records "
                                           "<p>Are you sure you want to delete all records "),
                                        QMessageBox::No|QMessageBox::Default, QMessageBox::No|QMessageBox::Escape, QMessageBox::NoButton);
    if (status == QMessageBox::Yes)
        return model->clear();

    */
    int status = QMessageBox::question(this, tr("Delete all Records ?"),
                                       tr("This operation will delete all saved records. "
                                          "<p>Do you want to remove all saved records ? "
                                       ), tr("Yes, Delete all records"), tr("No !"),
                                       QString(), 1, 1);
    if (status == 0) {
        int rowCount = model->rowCount();
        model->removeRows(0, rowCount);
    }



}


void MainWindow::aboutDialog()
{

    QMessageBox::about(this, "About RMS System",
                       "RMS System 2.0"
                          "<p>Copyright &copy; 2005 Inc."
                          "This is a simple application to demonstrate the use of windows,"
                          "tool bars, menus and dialog boxes");
}
