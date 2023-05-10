#include "mainwindow.h"
#include "exitdialog.h"

#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set a global stylesheet to set the theme
    QFile File(":/global_stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    a.setStyleSheet(StyleSheet);

    // Spin up the main window
    MainWindow w;
    w.show();

    // Launch
    return a.exec();
}
