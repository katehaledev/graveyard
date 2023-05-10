#include "aboutdialog.h"
#include "ui_aboutdialog.h"

void AboutDialog::aboutClicked(bool c)
{
    exec();
}

AboutDialog::AboutDialog(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
