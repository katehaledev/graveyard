#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

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
    QHBoxLayout *button_layout;
    QVBoxLayout *label_and_buttons_layout;

protected:
    void createSignalsAndSlots();
    void layoutMembers();


signals:
    void closeApplication();

public slots:
    void exitClicked(bool c);
};

#endif // EXITDIALOG_H
