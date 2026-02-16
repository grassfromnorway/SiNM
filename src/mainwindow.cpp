#include <QCoreApplication>
#include <QVBoxLayout>
#include <QSystemTrayIcon>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QPushButton>
#include "mainwindow.h"
#include "version.h"
#include "dbg.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    

    setWindowTitle(QString("SiNM v") + PROJECT_VERSION);
    resize(480,270);


    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *layout = new QVBoxLayout(central);
    label = new QLabel(central);


    layout->addWidget(label);

    tray = new QSystemTrayIcon(this);
    tray->setToolTip("SiNM");
    tray->setIcon(QIcon("../assets/sinm.png"));
    tray->show();
    connect(tray, &QSystemTrayIcon::activated,
            this, &MainWindow::iconActivated);


    //button for mvp, will be changed to global keybind in later versions
    
    QPushButton *screenshotButton = new QPushButton(central);
    screenshotButton->setText(tr("Screenshot"));    

    connect(screenshotButton, &QPushButton::clicked,
            this, &MainWindow::onScreenshotButtonClicked);

}


MainWindow::~MainWindow(){
    logMessage("Deconstructor ran in mainwindow.cpp", db.F);
}

void MainWindow::setLabelText(const QString &text){
    label->setText(text);

}

QString MainWindow::getLabelText() const{
    return label->text();
}

void MainWindow::trayMessage(const QString &title, const QString &message, const QIcon &icon, int millisecondsTimeoutHint){
    tray->showMessage(title, message, icon, millisecondsTimeoutHint);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{

    switch (reason) {
    case QSystemTrayIcon::Trigger:
        show();
        move(windowX, windowY);
        raise();
        activateWindow();
        logMessage("Ran show main window", db.I);
        
    case QSystemTrayIcon::DoubleClick:
        break;
    case QSystemTrayIcon::MiddleClick:
        logMessage("Escape on widget ran, cleanly terminating..", db.F);
        QCoreApplication::quit();
        break;
    default:
        ;
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    windowX = x();
    windowY = y();
    logMessage(("Hiding window, saved X value is " + std::to_string(windowX)).c_str(), db.I);
    logMessage(("Hiding window, saved Y value is " + std::to_string(windowY)).c_str(), db.I);
    hide();
    event->ignore();
    
}

void MainWindow::onScreenshotButtonClicked(){
    ScreenshotWindow *win = new ScreenshotWindow(this);
    win->startCapture();
}