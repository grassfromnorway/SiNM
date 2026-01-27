#include "mainwindow.h"
#include "version.h"
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    setWindowTitle(QString("SiNM v") + PROJECT_VERSION);
    resize(480,270);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *layout = new QVBoxLayout(central);

    label = new QLabel(QString("Welcome to v") + PROJECT_VERSION + QString(" Of SiNM!"), central);

    layout->addWidget(label);




};


MainWindow::~MainWindow(){


}