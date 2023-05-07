#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // When the Exit menu action is clicked, let the Exit Dialog know
    ExitDialog ed;
    connect(ui->actionExit, &QAction::triggered, &ed, &ExitDialog::exitClicked);
    //connect(ui->actionExit, &QAction::triggered, this, [=](){ std::cout << "Exit triggered" << std::endl; });


    // When the Exit Dialog sends it's cancel button "clicked" signal, close the app:
    connect(&ed, &ExitDialog::closeApplication, this, &MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;

}


