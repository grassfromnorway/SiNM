#include <QApplication>
#include <QWidget>
#include <QLabel>
#include "version.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    return app.exec();
}