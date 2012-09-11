/* 
 * File:   connectPanelClass.h
 * Author: lukasz
 *
 * Created on 9 wrzesień 2012, 00:38
 */

#ifndef CONNECTPANELCLASS_H
#define	CONNECTPANELCLASS_H
#include <QtGui>
#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>


using namespace std;

class connectPanelClass: public QDialog{
     Q_OBJECT
public:
    connectPanelClass(string *list,QWidget *parent=0);
    string getDeviceName();
    virtual ~connectPanelClass();
private  slots:
    void connectWithDevice();
private:
    QListWidget *lw;
    QPushButton *connectWith;
    string deviceName;
};

#endif	/* CONNECTPANELCLASS_H */

