#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // When the Exit menu action is clicked, let the Exit Dialog know
    ExitDialog ed;
    QObject::connect(ui->actionExit, SIGNAL(triggered(bool)), &ed, SLOT(&ExitDialog::close_clicked(bool)));

    // When the Exit Dialog sends it's cancel button "clicked" signal, close the app:
    QObject::connect(&ed, SIGNAL(&ExitDialog::closeApplication()), this, SLOT(&QWidget::close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


