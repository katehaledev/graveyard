#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // When the Exit menu action is clicked, let the Exit Dialog know
    ExitDialog ed;
    connect(ui->actionExit, SIGNAL(triggered()), &ed, SLOT(closeClicked()));

    // When the Exit Dialog sends it's cancel button "clicked" signal, close the app:
    QObject::connect(&ed, SIGNAL(closeApplication()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


