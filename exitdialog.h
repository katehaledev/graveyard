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
    /**
     * @brief ExitDialog : Creates an instance of an ExitDialog
     * @param parent
     */
    explicit ExitDialog(QDialog *parent = nullptr);

    /**
     * Base destructor.
     */
    ~ExitDialog();

private:
    QLabel* title_label;
    QPushButton* yes_button;
    QPushButton* cancel_button;
    QHBoxLayout *button_layout;
    QVBoxLayout *label_and_buttons_layout;

protected:
    /**
     * @brief createSignalsAndSlots: Sets up connections for signals and slots within
     * ExitDialog.
     */
    void createSignalsAndSlots();

    /**
     * @brief layoutMembers: Performs all layout logic for the GUI display of ExitDialog.
     */
    void layoutMembers();


signals:
    /**
     * @brief closeApplication: SIGNAL that emits when the user decides to exit the app.
     */
    void closeApplication();

public slots:
    /**
     * @brief exitClicked: SLOT that will cause the ExitDialog to display when the "Exit" menu
     * action is clicked.
     *
     * @param c: unused, just here to match the QAction signal "triggered(bool)"
     */
    void exitClicked(bool c);

    /**
     * @brief okayClicked: SLOT that closes the ExitDialog and then emits a signal to close
     * the application.
     */
    void okayClicked();
};

#endif // EXITDIALOG_H
