/* 
 * File:   SearchDevices.h
 * Author: pablo
 *
 * Created on 15 sierpień 2012, 12:41
 */
//juz dziala!
#ifndef SEARCHDEVICES_H
#define	SEARCHDEVICES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>

using namespace std;

class bluetooth
{
private:
    inquiry_info *ii;
    char adress[20];
    char name[20];
    int dev_id, sock;
    int lenght;
    int max_rsp;
    int num_rsp;
    int flags;
    int i;
    string arrayOfDevices[20];
    string nameOfDevices[20];
public:
    bluetooth();
    ~bluetooth();
    string * returnArrayOfNames();
    int sizeOfArrayNames();
    string * returnAdressOfDevices();
    void discover();
    
    
};

#endif	/* SEARCHDEVICES_H */

