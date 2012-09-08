//#include "SearchDevices.h"
#include <fstream>
#include<stdio.h>
#include<iostream>

using namespace std;






/*bluetooth::bluetooth()
{
  this->ii=NULL;
    this->i=0;
    this->lenght = 10;
    this->max_rsp = 255;
    
    this->adress=new char[19];
    this->name=new char[40];
    
    memset (this->adress,0,19);
    memset (this->name,0,40);
    
    this->dev_id = hci_get_route(NULL);
    this->sock = hci_open_dev( dev_id );
    if(this->dev_id < 0 || this->sock < 0 )
    {
        perror("BLADKURw");
        exit(1);
    }
    
}

void bluetooth::discover()
{
    ofstream wpisz;
    wpisz.open("dane.txt");
    this->flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
    
    num_rsp = hci_inquiry(dev_id, lenght, max_rsp, NULL, &ii, flags);
    if( num_rsp < 0 ) perror("no to lepa");
    
    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, adress);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), 
            name, 0) < 0)
        strcpy(name, "[nieznany]");
        wpisz<<"Nazwa urządzenia:";
        wpisz<<endl;
        wpisz<<name;
        wpisz<<endl;
        wpisz<<"Adres urządzenia";
        wpisz<<adress;
        //printf("%s  %s\n", adress, name);
        
    }
    wpisz.close();
    
    
}

bluetooth::~bluetooth()
{
    free( ii );
    close( sock );
   
}
*/