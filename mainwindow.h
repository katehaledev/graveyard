#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include "exitdialog.h"
#include "aboutdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QDialog *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    ExitDialog *ed;
    AboutDialog *ad;

};
#endif // MAINWINDOW_H
