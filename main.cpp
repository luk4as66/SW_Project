/*
 * File:   main.cpp
 * Author: lukasz
 *
 * Created on 9 sierpień 2012, 20:16
 */

#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QApplication>
#include "MainWindow.h"
//kurwa
void center(QWidget &widget){
    int x, y;
    int screenWidth, screenHeight, width, height;
    QSize windowSize;
    
    QDesktopWidget *desktop = QApplication::desktop();
    
    width = 1;
    height = 1;
    
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth - width)/2;
    y = (screenHeight - height)/2;
    
    
    widget.move(100,100);
    
}




int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    
    
    
    
    MainWindow main;
    main.setWindowTitle("SW PROJECT");
    main.show();
    center(main);
    
    return app.exec();
}
