#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QObject>

// Forward declarations
class QLabel;
class QPushButton;

class ExitDialog : public QObject
{
    Q_OBJECT
public:
    explicit ExitDialog(QObject *parent = nullptr);
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
    void closeApplication(bool value);

protected slots:
    void closeClicked();
};



#endif // EXITDIALOG_H
