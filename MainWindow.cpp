/* 
 * File:   MainWindow.cpp
 * Author: lukasz
 * 
 * Created on 11 sierpień 2012, 13:10
 */

#include "MainWindow.h"
#include <QDialog>
#include <QTextEdit>
#include <QFont>
#include <fstream>
#include<iostream>
#include<stdio.h>
#include <QTextCodec>

using namespace std;


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) {

    
    int btnWidth = 150;
    int btnHeight = 40;
    QFont font;
    font.setPointSize(50);
    font.setBold(true);
    
    SearchDevicesAction = new QAction(tr("&Search"), this);
    
    fileMenu =  menuBar()->addMenu(tr("&File"));
    
    Exit = new QAction(tr("&Exit"), this);
    
    ViewDevices = new QAction(tr("&View Devices"), this);
    
    widgetMenuSearchDevices = new QPushButton("Search Devices...", this);
    widgetMenuSearchDevices->setGeometry(10, 10, btnWidth, btnHeight);
    
    widgetMenuViewDevices = new QPushButton("View Devices", this);
    widgetMenuViewDevices->setGeometry(10, btnHeight+11, btnWidth, btnHeight);
    
    widgetMenuConnect = new QPushButton("Connect...", this);
    widgetMenuConnect->setGeometry(10, (2*btnHeight)+11, btnWidth, btnHeight);
    
    widgetMenuExit = new QPushButton("Exit", this);
    widgetMenuExit->setGeometry(10, (3*btnHeight)+11, btnWidth, btnHeight);
    
    showDevices = new QTextEdit(this);
    showDevices -> setReadOnly(true);
    showDevices->setGeometry(180, 30, 410, 60);
    
    logLabel = new QLabel("log output:",this);
    logLabel -> setGeometry(180,10,100,15);

    temperatureLabel = new QLabel("temperature: ",this);
    temperatureLabel -> setGeometry(10,260,80,15);
    
    moveAreaLabel = new QLabel("Cursor movement area: ",this);
    moveAreaLabel -> setGeometry(180,95,150,15);
    
    
    //to musi byc aktualizowana na bierzaco 
    tempDeegreLabel = new QLabel("-0 C",this);
    tempDeegreLabel -> setFont(font);
    tempDeegreLabel -> setGeometry(90,220,200,100);
    
    
    
    connect(SearchDevicesAction, SIGNAL(triggered()), this, SLOT(find()));
    connect(Exit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ViewDevices, SIGNAL(triggered()), this, SLOT(discovered()));
    connect(widgetMenuSearchDevices, SIGNAL(clicked()), qApp, SLOT(find()));
    connect(widgetMenuViewDevices, SIGNAL(clicked()), this, SLOT(discovered()));
    connect(widgetMenuConnect, SIGNAL(clicked()), this, SLOT(connectToDevice()));
    connect(widgetMenuExit, SIGNAL(clicked()), qApp, SLOT(quit()));

    fileMenu->addAction(SearchDevicesAction);
    fileMenu->addAction(Exit);
    fileMenu->addAction(ViewDevices);
    
    
    
    
    
    
    
    
    
    this->resize(600,300);
}
   
void MainWindow:: find(){
 
/* bluetooth search;
 search.discover();
 statusBar()->showMessage("Searching for devices...");
 */
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
    
    logText+= bufor;
    logText+="\n";
    
    //string *tempText = new string();
    showDevices->setText(trUtf8(logText.c_str()));
    
    
}
void MainWindow :: connectToDevice(){
    //TODO logic
    //wylistowac dostepne urzadzenia
    string fakeList[4]={"device1","device2","device3","device4"};
    connectPanel = new connectPanelClass(fakeList,this);
    connectPanel -> resize(300,200);
    
    connectPanel -> show();
    logText += "glupi text";
    logText+="\n";
    showDevices->setText(logText.c_str());
    
    
}
MainWindow::~MainWindow() {
}

