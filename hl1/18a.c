/*
============================================================================
Name : 18a.c
Author : Sejal Khandelwal
Description : Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.   
Date: 8th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
        int i ,fd;
        struct{
                int train_num;
                int ticket_count;
        }db[3];
        for (i=0;i<3;i++){
                db[i].train_num=i+1;
                db[i].ticket_count=0;
        }
        fd=open("record.txt",O_RDWR);
        write(fd,db,sizeof(db));
        close(fd);
}
