/* 
 * File:   MainWindow.cpp
 * Author: lukasz
 * 
 * Created on 11 sierpień 2012, 13:10
 */

#include "MainWindow.h"
#include "SearchDevices.h"
#include "connectPanelClass.h"
#include <QDialog>
#include <QTextEdit>
#include <QFont>
#include <fstream>
#include<iostream>
#include<stdio.h>
#include <QTextCodec>
#include <QProgressBar>

using namespace std;


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) {

    
   
    int btnWidth = 150;
    int btnHeight = 40;
    QFont font;
    font.setPointSize(50);
    font.setBold(true);
    
    QProgressBar *progressbar = new QProgressBar(this);
    progressbar->setGeometry(10, (3*btnHeight)+180, 200, 20);
    progressbar->setRange(0,100);
    
    SearchDevicesAction = new QAction(tr("&Search"), this);
    
    fileMenu =  menuBar()->addMenu(tr("&File"));
    
    Exit = new QAction(tr("&Exit"), this);
    
    ViewDevices = new QAction(tr("&View Devices"), this);
    
    widgetMenuSearchDevices = new QPushButton("Search Devices...", this);
    widgetMenuSearchDevices->setGeometry(10, 19, btnWidth, btnHeight);
    
    widgetMenuViewDevices = new QPushButton("View Devices", this);
    widgetMenuViewDevices->setGeometry(10, btnHeight+20, btnWidth, btnHeight);
    
    widgetMenuConnect = new QPushButton("Connect...", this);
    widgetMenuConnect->setGeometry(10, (2*btnHeight)+20, btnWidth, btnHeight);
    
    widgetMenuExit = new QPushButton("Exit", this);
    widgetMenuExit->setGeometry(10, (3*btnHeight)+20, btnWidth, btnHeight);
    
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
    connect(widgetMenuSearchDevices, SIGNAL(clicked()), this, SLOT(find()));
    connect(widgetMenuViewDevices, SIGNAL(clicked()), this, SLOT(discovered()));
    connect(widgetMenuConnect, SIGNAL(clicked()), this, SLOT(connectToDevice()));
    connect(widgetMenuExit, SIGNAL(clicked()), qApp, SLOT(quit()));

    fileMenu->addAction(SearchDevicesAction);
    fileMenu->addAction(Exit);
    fileMenu->addAction(ViewDevices);
    
    
    
    temp = new string [search.sizeOfArrayNames()];
    temp2 = new string [search.sizeOfArrayNames()];
    
    
    
    
    this->resize(630,330);
}
   
void MainWindow:: find(){
 
 
 search.discover();
 statusBar()->showMessage("Searching for devices...");
 
 
}

void MainWindow :: discovered()
{
    
    
    
    
    if(search.sizeOfArrayNames()==0)
    {
      logText+"brak urzadzen";
      cout<<"bla"<<endl;
    }
    else
    {
    temp = search.returnArrayOfNames();
    temp2 = search.returnAdressOfDevices();
    for(int i=0;i<search.sizeOfArrayNames();i++)
    {
        fakeList = new string[search.sizeOfArrayNames()];
        logText+="nazwa urzadzenia: ";
        logText+= temp2[i];
        logText+= '\n';
        logText+="adres: ";
        logText+= temp[i];
        logText+= '\n';
        
    }}
    
   
    
    
    
    
    showDevices->setText(trUtf8(logText.c_str()));
   
    
    
}
void MainWindow :: connectToDevice(){
   
        if(search.sizeOfArrayNames()==0)
        {
            cout<<"bla"<<endl;
            logText+"brak urzadzen";
        }
        else
        {
         
         fakeList = search.returnArrayOfNames();
         connectPanel = new connectPanelClass(fakeList,this);
         connectPanel -> resize(300,200);
         connectPanel -> show();
        }
    logText+='\n';
    showDevices->setText(logText.c_str());
    
    
}
MainWindow::~MainWindow() {
    
}

