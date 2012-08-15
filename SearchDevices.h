/* 
 * File:   SearchDevices.h
 * Author: pablo
 *
 * Created on 15 sierpień 2012, 12:41
 */

#ifndef SEARCHDEVICES_H
#define	SEARCHDEVICES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include </usr/include/bluetooth/bluetooth.h>
#include </usr/include/bluetooth/hci.h>
#include </usr/include/bluetooth/hci_lib.h>


class bluetooth
{
private:
    inquiry_info *ii;
    char *adress;
    char *name;
    int dev_id, sock;
    int lenght;
    int max_rsp;
    int num_rsp;
    int flags;
    int i;
public:
    bluetooth();
    ~bluetooth();
    void discover();
};

#endif	/* SEARCHDEVICES_H */

