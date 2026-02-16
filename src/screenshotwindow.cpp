#include <QCoreApplication>
#include <QVBoxLayout>
#include <QSystemTrayIcon>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <QGuiApplication>
#include <thread>
#include <chrono>
#include "screenshotwindow.h"
#include "imagewindow.h"
#include "version.h"
#include "dbg.h"


ScreenshotWindow::ScreenshotWindow(QWidget *parent) : QWidget(parent), isSelecting(false){
    logMessage("Ran screenshotwindow main constructor", db.S);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);
    QScreen *screen = QGuiApplication::primaryScreen();
    frozenScreenshot = screen->grabWindow(0);
    showFullScreen();

    logMessage("Created screenshotwindow main constructor", db.S);
}

ScreenshotWindow::~ScreenshotWindow(){
    logMessage("Deconstructor ran in screenshotwindow.cpp", db.F);
}

void ScreenshotWindow::startCapture(){
    logMessage("Ran startCapture slot member", db.S);
    show();
    raise();
    showFullScreen();
    activateWindow();
    logMessage("Finished startCapture slot member and queing for deletion", db.S);
    //deleteLater();  //do not forget for memory leaks
}

void ScreenshotWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0, frozenScreenshot);
    painter.fillRect(rect(), QColor(0,0,0,85));

    if (isSelecting){
        painter.setPen(QPen(Qt::white, 2));
        painter.drawRect(QRect(startPoint, endPoint));
    }


}

void ScreenshotWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
         startPoint = event->pos();
         isSelecting = true;
         logMessage(("Startpos frame, xy pair is " + std::to_string(startPoint.x()) + " " + std::to_string(startPoint.y())).c_str(), db.I);
        //certified overloading / template hater or js better code

    }
}

void ScreenshotWindow::mouseMoveEvent(QMouseEvent *event){
    if(isSelecting){
        endPoint = event->pos();
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); //no drawing updates thousands of times per second
        update();

    }
}

void ScreenshotWindow::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        endPoint = event->pos();
        isSelecting = false;
        logMessage(("Endpoint frame, xy pair is " + std::to_string(endPoint.x()) + " " + std::to_string(endPoint.y())).c_str(), db.I);
        //====>passing to screenshotwindow

        ImageWindow *imgWin = new ImageWindow(nullptr);
        imgWin->setScreenshot(frozenScreenshot, startPoint, endPoint);
        imgWin->show();
        
        deleteLater();
    }
}