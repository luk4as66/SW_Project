/* 
 * File:   MainWindow.cpp
 * Author: lukasz
 * 
 * Created on 11 sierpień 2012, 13:10
 */

#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) {
    QAction *quit = new QAction("&Find Devices...", this);
    QMenu *file;
    SearchDevicesLabel = new QLabel("Find Devices..");
    file = menuBar()->addMenu("&Connect");
    statusBar()->showMessage("QSimulate has started");
   
    connect (quit, SIGNAL(triggered()), SearchDevicesLabel, SLOT(find()));  
     file->addAction(quit);
    resize(600,600);
}
void MainWindow:: find(){
 statusBar()->showMessage("Searching for devices...");
}
MainWindow::~MainWindow() {
}

