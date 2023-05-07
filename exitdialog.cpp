#include <QtGui>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include "exitdialog.h"

void ExitDialog::create_signals_slots()
{
    QObject::connect(this->cancel_button, SIGNAL( clicked() ),this, SLOT( closeClicked() );
}

void ExitDialog::layout_members()
{

}

void ExitDialog::closeClicked()
{
    emit closeApplication(true);
}

void ExitDialog::initialize()
{
    create_members();
    layout_members();
}

ExitDialog::ExitDialog(QDialog *parent)
    : QDialog{parent}
{
    this->title_label = new QLabel("Exit?");
    this->okay_button = new QPushButton("OK");

    this->cancel_button = new QPushButton("Cancel");
    // Cancel will be the button that activates if a user presses the Enter key
    this->cancel_button->setDefault(true);
}


~ExitDialog()
{

}
