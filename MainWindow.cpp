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

#define MOUSEFILE "/dev/input/event5"
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
    
     dpy = XOpenDisplay(NULL);
  XQueryPointer(dpy,DefaultRootWindow(dpy),&root,&child,
              &rootX,&rootY,&winX,&winY,&mask); 
  fd = open(MOUSEFILE, O_RDONLY);
  if(fd == -1) {
    perror("opening device");
    exit(EXIT_FAILURE);
  }
    
    
    
    
    
    
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
    
    mousePosX = new QLabel("x=NaN ", this);
    mousePosX -> setGeometry(180,200,50,15);
    
    mousePosY = new QLabel("y=NaN ", this);
    mousePosY -> setGeometry(230,200,50,15);
    
    //to musi byc aktualizowana na bierzaco 
    tempDeegreLabel = new QLabel("-0 C",this);
    tempDeegreLabel -> setFont(font);
    tempDeegreLabel -> setGeometry(90,220,200,100);
    
    qApp -> installEventFilter(this);
    
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
/*
 * ruch myszy po oknie aplikacji;
 */
bool MainWindow::eventFilter(QObject* obj, QEvent* event){
    if(event->type() == QEvent::MouseMove){
   // QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QString xPos;
    //    xPos = "x="+xPos.setNum(mouseEvent->pos().x());
        QString yPos;
    //    yPos = "y="+yPos.setNum(mouseEvent->pos().y());
        

 

 read(fd, &ie, sizeof(struct input_event));
    if (ie.type == 2) {
      if (ie.code == 0) { rootX += ie.value; }
      else if (ie.code == 1) { rootY += ie.value; }
     // printf("time%ld.%06ld\tx %d\ty %d\n", 
     //    ie.time.tv_sec, ie.time.tv_usec, rootX, rootY);
      
    } else if (ie.type == 1) {
      if (ie.code == 272 ) { 
        printf("Mouse button ");
        if (ie.value == 0)  
          printf("released!!\n");
        if (ie.value == 1)  
          printf("pressed!!\n");
    } else {
        printf("time %ld.%06ld\ttype %d\tcode %d\tvalue %d\n",
            ie.time.tv_sec, ie.time.tv_usec, ie.type, ie.code, ie.value);
    }
  }
         xPos = "x="+xPos.setNum(rootX);
        yPos = "x="+yPos.setNum(rootY);
      mousePosX -> setText(xPos);
        mousePosY -> setText(yPos);
        
    }
    
    return false;
}



MainWindow::~MainWindow() {
    
}

