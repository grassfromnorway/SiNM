#include <QCoreApplication>
#include <QVBoxLayout>
#include <QSystemTrayIcon>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include "imagewindow.h"
#include "version.h"
#include "dbg.h"


ImageWindow::ImageWindow(QWidget *parent) : QWidget(parent){
    setWindowTitle("Screenshot");

    imageLabel = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);




}

ImageWindow::~ImageWindow(){

}

void ImageWindow::setScreenshot(const QPixmap &screenshot, QPoint start, QPoint end) {
    QRect cropRect = QRect(start, end).normalized();

    croppedImage = screenshot.copy(cropRect);

    imageLabel->setPixmap(croppedImage);

    resize(croppedImage.size());


}