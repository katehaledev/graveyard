#include <QtGui>
#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>

#include "exitdialog.h"

void ExitDialog::createSignalsAndSlots()
{
    connect(cancel_button, &QPushButton::clicked,this, [=](){ close(); });
    connect(okay_button, &QPushButton::clicked, this, [=](){ emit closeApplication(); });
}

void ExitDialog::layoutMembers()
{
    label_and_buttons_layout->addWidget(title_label);
    button_layout->addWidget(okay_button);
    button_layout->addWidget(cancel_button);
    label_and_buttons_layout->addItem(button_layout);

    setLayout(label_and_buttons_layout);
}

void ExitDialog::exitClicked(bool c)
{
    std::cout << "exitClicked fired" << std::endl;
    printf("Slot triggered!");
}


ExitDialog::~ExitDialog()
{

}

ExitDialog::ExitDialog(QDialog *parent)
    : QDialog{parent}
{
    label_and_buttons_layout = new QVBoxLayout();
    button_layout = new QHBoxLayout();
    title_label = new QLabel("Exit?");
    okay_button = new QPushButton("OK");

    cancel_button = new QPushButton("Cancel");
    // Cancel will be the button that activates if a user presses the Enter key
    cancel_button->setDefault(true);

    createSignalsAndSlots();
    layoutMembers();


}


