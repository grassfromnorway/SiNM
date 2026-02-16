#include <QApplication>
#include <QCloseEvent>
#include <QtGlobal>
#include "version.h"
#include "mainwindow.h"
#include "dbg.h" //custom debug message implementation



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    dbg db;
    qSetMessagePattern(""); //comment to enable debug
    logMessage("Starting debug", db.S);

    app.setQuitOnLastWindowClosed(false);
    app.setWindowIcon(QIcon("../assets/sinm.png"));

    window.setLabelText("SiNM " + QString(PROJECT_VERSION));
    window.show();



    logMessage("Main.cpp loop finished", db.I);
    return app.exec();
}