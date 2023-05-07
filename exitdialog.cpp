#include <QtGui>
#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>

#include "exitdialog.h"

/**
 * @brief ExitDialog::createSignalsAndSlots : Connects the "Cancel" and "Yes" QPushButtons to
 * slots within ExitDialog.
 *
 * "Cancel" will close the ExitDialog and return focus to the MainWindow
 *
 * "Yes" will close the MainWindow and close the ExitDialog
 */
void ExitDialog::createSignalsAndSlots()
{
    connect(cancel_button, &QPushButton::clicked,this, [=](){ close(); });
    connect(yes_button, &QPushButton::clicked, this, &ExitDialog::okayClicked);
}


/**
 * @brief ExitDialog::layoutMembers : Lays out the
 * GUI for the ExitDialog, which consists of a QLabel and 2 QPushButtons.
 */
void ExitDialog::layoutMembers()
{
    label_and_buttons_layout->addWidget(title_label);
    button_layout->addWidget(yes_button);
    button_layout->addWidget(cancel_button);
    label_and_buttons_layout->addItem(button_layout);

    setLayout(label_and_buttons_layout);
}

/**
 * @brief ExitDialog::exitClicked : SLOT function that will
 * launch the ExitDialog,
 *
 * @param c : unused param, here because the triggered() signal has a default bool param
 */
void ExitDialog::exitClicked(bool c)
{
    exec();
}

/**
 * @brief ExitDialog::okayClicked : SLOT function that will close the ExitDialog
 * and then emit a SIGNAL (closeApplication())
 * to close the MainWindow
 */
void ExitDialog::okayClicked()
{
    close();
    emit closeApplication();
}

/**
 * @brief ExitDialog::ExitDialog : A very simple box that will
 * make sure the user actually wants to exit the application.
 *
 * @param parent
 */
ExitDialog::ExitDialog(QDialog *parent)
    : QDialog{parent}
{
    label_and_buttons_layout = new QVBoxLayout();
    button_layout = new QHBoxLayout();
    title_label = new QLabel("Are you sure you want to Exit?");
    yes_button = new QPushButton("Yes");

    cancel_button = new QPushButton("Cancel");
    // Cancel will be the button that activates if a user presses the Enter key
    cancel_button->setDefault(true);

    title_label->setAlignment(Qt::AlignHCenter);
    setWindowTitle("Exit Graveyard?");

    createSignalsAndSlots();
    layoutMembers();
}

/**
 * @brief ExitDialog::~ExitDialog: Base destruction that deletes an instance
 * of ExitDialog.
 */
ExitDialog::~ExitDialog()
{
    delete this;

}


