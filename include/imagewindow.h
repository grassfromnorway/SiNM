#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H


#include <QMainWindow>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QCloseEvent>



class ImageWindow : public QWidget {
    Q_OBJECT

public:
    ImageWindow(QWidget *parent = nullptr);
    ~ImageWindow();

    void setScreenshot(const QPixmap &screenshot, QPoint start, QPoint end);

private:
    QLabel *imageLabel;
    QPixmap croppedImage;




protected:


};



#endif