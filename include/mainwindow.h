#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <screenshotwindow.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setLabelText(const QString &text);
    QString getLabelText() const;

    void trayMessage(const QString &title, const QString &message, const QIcon &icon, int millisecondsTimeoutHint);

    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    void onScreenshotButtonClicked();






protected:
    void closeEvent(QCloseEvent *event);


private:
    QLabel *label;
    QSystemTrayIcon *tray;
    int windowX;
    int windowY;
    ScreenshotWindow *screenshotWin;

};





#endif