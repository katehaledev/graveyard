#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AboutDialog; }
QT_END_NAMESPACE

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QDialog *parent = nullptr);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui_ad;

public slots:
    void aboutClicked(bool c);
};
#endif // ABOUTDIALOG_H
