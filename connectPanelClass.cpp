/* 
 * File:   connectPanelClass.cpp
 * Author: lukasz
 * 
 * Created on 9 wrzesień 2012, 00:38
 */

#include "connectPanelClass.h"
#include <iostream>
#include <QtCore>
#include <QThread>
#include <QTime>

using namespace std;

connectPanelClass::connectPanelClass(string *list, QWidget *parent):QDialog(parent) {
    
    int arraySize = sizeof(list)-1;
    cout<<sizeof(list);
    QVBoxLayout *vbox = new QVBoxLayout();
  vbox->setSpacing(10);
    // must add it to another layout.
  QHBoxLayout *hbox = new QHBoxLayout(this);

  lw = new QListWidget(this);
  
  
    for(int i=0;i<arraySize;i++){
        lw->addItem(list[i].c_str()); 
    }

  
  connectWith = new QPushButton("Connect", this);
    
  vbox->setSpacing(3);
  vbox->addStretch(1);
  vbox->addWidget(connectWith);
  
  
  connect(connectWith, SIGNAL(clicked()), this, SLOT(connectWithDevice()));
  
  
  hbox->addWidget(lw);
  hbox->addSpacing(15);
  hbox->addLayout(vbox);
  
  
  
  
   setLayout(hbox);
  
 
}

void connectPanelClass::connectWithDevice(){
    
    QListWidgetItem *curitem = lw->currentItem();
    QString text = curitem->text();
    
    
    
    cout<<text.toStdString();
    struct sockaddr_rc addr = { 0 };
    int s, status;
    char dest[18] = "00:12:6F:25:06:10";
    char buff[10];

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );

    // connect to server
    status = ::connect(s, (struct sockaddr *)&addr, sizeof(addr));

    // send a message
    if( status == 0 ) {
        sleep(4);
        //status = write(s, "aaaaaa", 6);
        status = read(s, buff, 10 );
        
        sleep(4);
        printf("status=%d", status);
        printf("bufor=%s", buff);
        
        
        
    }
    
    if( status < 0 ) perror("uh oh");

    ::close(s);
    
    
    
    
}
string connectPanelClass::getDeviceName(){
    return deviceName;
}

connectPanelClass::~connectPanelClass() {
    
}

