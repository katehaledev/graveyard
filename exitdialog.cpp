#include <QtGui>
#include <QVBoxLayout>
#include <QMessageBox>

#include "exitdialog.h"

void ExitDialog::createSignalsAndSlots()
{
    connect(cancel_button, SIGNAL( clicked() ),this, SLOT( closeClicked() ));
}

void ExitDialog::layoutMembers()
{
    label_and_buttons_layout->addWidget(title_label);
    button_layout->addWidget(okay_button);
    button_layout->addWidget(cancel_button);
    label_and_buttons_layout->addItem(button_layout);

    setLayout(label_and_buttons_layout);
}

void ExitDialog::closeClicked()
{
    emit closeApplication();
}

ExitDialog::~ExitDialog()
{
}

ExitDialog::ExitDialog(QDialog *parent)
    : QDialog{parent}
{
    window = new QWidget;
    label_and_buttons_layout = new QVBoxLayout();
    button_layout = new QHBoxLayout(window);
    title_label = new QLabel("Exit?");
    okay_button = new QPushButton("OK");

    cancel_button = new QPushButton("Cancel");
    // Cancel will be the button that activates if a user presses the Enter key
    cancel_button->setDefault(true);

    layoutMembers();

    exec();



}


