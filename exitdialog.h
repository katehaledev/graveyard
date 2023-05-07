#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLabel>

class ExitDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ExitDialog(QDialog *parent = nullptr);
    ~ExitDialog();

private:
    QLabel* title_label;
    QPushButton* okay_button;
    QPushButton* cancel_button;

protected:
    void create_members();
    void create_signals_slots();
    void layout_members();


signals:
    void closeApplication();

protected slots:
    void closeClicked();
};

#endif // EXITDIALOG_H
