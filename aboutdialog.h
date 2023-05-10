#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QDialog *parent = nullptr);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui;

public slots:
    void aboutClicked(bool c);
};
#endif // ABOUTDIALOG_H
