#ifndef SCREENSHOTWINDOW_H
#define SCREENSHOTWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QCloseEvent>



class ScreenshotWindow : public QWidget {
    Q_OBJECT

public:
    ScreenshotWindow(QWidget *parent = nullptr);
    ~ScreenshotWindow();

    void startCapture();
    

private:
    QPixmap frozenScreenshot;


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QPoint startPoint;
    QPoint endPoint;
    bool isSelecting;
    


};

#endif