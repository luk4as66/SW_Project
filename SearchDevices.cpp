#include <fstream>
#include<stdio.h>
#include<iostream>
#include <string>
#include "SearchDevices.h"
#include <cstring>
#include <sstream>




using namespace std;






bluetooth::bluetooth()
{
    this->ii=NULL;
    this->i=0;
    this->lenght = 10;
    this->max_rsp = 255;
    this->num_rsp =0;
    
    
    
    memset (this->adress,0,19);
    memset (this->name,0,20);
    
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
    
    
    this->flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
    
    num_rsp = hci_inquiry(dev_id, lenght, max_rsp, NULL, &ii, flags);
    if( num_rsp < 0 ) perror("no to lepa");
    
    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, adress);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), 
            name, 0) < 0){
          strcpy(name, "[nieznany]");  
        }
           
        string str(name);
        string str2(adress);
        
        arrayOfDevices[i] = str2;
        nameOfDevices[i] = str;
        
    }
    
    
    
}

string * bluetooth::returnArrayOfNames()
{
    return nameOfDevices;
}

 int bluetooth :: sizeOfArrayNames()
 {
     return num_rsp;
 }
 
 string * bluetooth :: returnAdressOfDevices()
 {
     return arrayOfDevices;
 }



bluetooth::~bluetooth()
{
    free( ii );
    close( sock );
    
   
}
