/* 
 * File:   connectPanelClass.cpp
 * Author: lukasz
 * 
 * Created on 9 wrzesień 2012, 00:38
 */

#include "connectPanelClass.h"
#include <iostream>


using namespace std;

connectPanelClass::connectPanelClass(string *list, QWidget *parent):QDialog(parent){
    
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

void connectPanelClass :: connectWithDevice()
{
    struct sockaddr_rc addr = { 0 };
    int s, status;
    char dest[18] = "00:12:6F:25:06:10";
    char buff[10] = "baaaaaa"; 
    
    struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 }; //odbior
    char buf[1024] = { 0 };//odbior
    int  s2,client, bytes_read;//odbior
    socklen_t opt = sizeof(rem_addr);//odbior

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    s2 = s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    // set the connection parameters (who to connect to)
    
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );
    
    loc_addr.rc_family = AF_BLUETOOTH;//odbior
    loc_addr.rc_bdaddr = *BDADDR_ANY;//odbior
    loc_addr.rc_channel = (uint8_t) 1;//odbior
    bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));//odbior
    
    listen(s2, 1);

    // connect to server
    status = ::connect(s, (struct sockaddr *)&addr, sizeof(addr));
    client = ::accept(s2, (struct sockaddr *)&rem_addr, &opt);
    
    ba2str( &rem_addr.rc_bdaddr, buf );
    fprintf(stderr, "accepted connection from %s\n", buf);
    memset(buf, 0, sizeof(buf));

    for(int i=0;i<19;i++)
    {
    // send a message
    if( status == 0 ) {
        
        printf("good");
        status = write(s, "ccccc", 5);
        bytes_read = read(client, buf, sizeof(buf));
        cout<<"temp: "<<buf<<endl;
      if( bytes_read > 0 ) {
          
    }
     
    }
    }
    if( status < 0 ) perror("uh oh");

    ::close(s);
    ::close(s2);
    
    
}
void connectPanelClass::run()
{
    
}
}
connectPanelClass::~connectPanelClass() {
    
}

