#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>


MainWindow::MainWindow(QDialog *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /**
     * HOME VIEW
     */


    // When the Exit menu action is clicked, let the Exit Dialog know
    ed = new ExitDialog();
    QObject::connect(ui->actionExit, &QAction::triggered, ed, &ExitDialog::exitClicked);

    // When the Exit push button is clocked, let the Exit Dialog know
    QObject::connect(ui->exitButton_home, &QPushButton::clicked, ed, &ExitDialog::exitClicked);


    // When the Exit Dialog sends it's cancel button "clicked" signal, close the app:
    QObject::connect(ed, &ExitDialog::closeApplication, this, &MainWindow::close);

    // When the About button is clicked, let the About Dialog know
    ad = new AboutDialog();
    QObject::connect(ui->aboutButton_home, &QPushButton::clicked, ad, &AboutDialog::aboutClicked);


}

MainWindow::~MainWindow()
{
    delete ui;

}


