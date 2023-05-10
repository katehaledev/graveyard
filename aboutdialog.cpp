#include "aboutdialog.h"
#include "ui_aboutdialog.h"

void AboutDialog::aboutClicked(bool c)
{
    exec();
}

AboutDialog::AboutDialog(QDialog *parent) :
    QDialog(parent),
    ui_ad(new Ui::AboutDialog)
{
    ui_ad->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui_ad;
}
