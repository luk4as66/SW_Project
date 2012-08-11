/* 
 * File:   MainWindow.cpp
 * Author: lukasz
 * 
 * Created on 11 sierpień 2012, 13:10
 */

#include "MainWindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent):QWidget(parent) {
    QLabel *nameLabel = new QLabel(tr("Name:"));
    nameLine = new QLineEdit;
    QLabel *addressLabel = new QLabel(tr("Address:"));
     addressText = new QTextEdit;
}

MainWindow::MainWindow(const MainWindow& orig) {
}

MainWindow::~MainWindow() {
}

