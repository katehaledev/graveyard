#include <QtGui>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include "exitdialog.h"

void ExitDialog::create_signals_slots()
{
    //QObject::connect(cancel_button, SIGNAL( clicked() ),this, SLOT( closeClicked() ));
    connect(&cancel_button, &QPushButton::clicked, this, &ExitDialog::closeClicked );
}

void ExitDialog::layout_members()
{

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
    title_label = new QLabel("Exit?");
    okay_button = new QPushButton("OK");

    cancel_button = new QPushButton("Cancel");
    // Cancel will be the button that activates if a user presses the Enter key
    cancel_button->setDefault(true);
}


