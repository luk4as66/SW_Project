/* 
 * File:   MainWindow.cpp
 * Author: lukasz
 * 
 * Created on 11 sierpień 2012, 13:10
 */

#include "MainWindow.h"
#include <QDialog>
#include <QTextEdit>
#include <fstream>
#include<iostream>
#include<stdio.h>
 #include <QTextCodec>

using namespace std;


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) {
   
    /*
    QAction *quit = new QAction("&Find Devices...", this);
    QMenu *file;
    SearchDevicesLabel = new QLabel("Find Devices..");
    file = menuBar()->addMenu("&Connect");
    statusBar()->showMessage("QSimulate has started");
   
    //connect (quit, SIGNAL(triggered()), SearchDevicesLabel, SLOT(find()));  
    connect(SearchDevicesLabel, SIGNAL(clicked()), this, SLOT(find()));
     file->addAction(quit);
    resize(600,600);*/
    SearchDevicesAction = new QAction(tr("&Search"), this);
    fileMenu =  menuBar()->addMenu(tr("&File"));
    
    Exit = new QAction(tr("&Exit"), this);
    ViewDevices = new QAction(tr("&View Devices"), this);
    
    
    connect(SearchDevicesAction, SIGNAL(triggered()), this, SLOT(find()));
    connect(Exit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ViewDevices, SIGNAL(triggered()), this, SLOT(discovered()));

    fileMenu->addAction(SearchDevicesAction);
    fileMenu->addAction(Exit);
    fileMenu->addAction(ViewDevices);
    
    
    
    this->resize(600,600);
}
   
void MainWindow:: find(){
 
 bluetooth search;
 search.discover();
 statusBar()->showMessage("Searching for devices...");
}

void MainWindow :: discovered()
{
    
    fstream plik;
    plik.open( "dane.txt", std::ios::in | std::ios::out );
    
    if( plik.good() == true )
    {
    cout << "Uzyskano dostep do pliku!" << std::endl;
    
    } else cout << "Dostep do pliku zostal zabroniony!" << std::endl;
    
    char bufor[ 1024 ];
    plik.read( bufor, 1024 );
    
    QTextEdit *discovered;
    discovered = new QTextEdit();
    
    discovered->showNormal();
    string *tempText = new string();
    discovered->setText(trUtf8(bufor));
    
    
}
MainWindow::~MainWindow() {
}

