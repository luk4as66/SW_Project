/* 
 * File:   connectPanelClass.cpp
 * Author: lukasz
 * 
 * Created on 9 wrzesień 2012, 00:38
 */

#include "connectPanelClass.h"
#include <iostream>

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


connectPanelClass::~connectPanelClass() {
}

