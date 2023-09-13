/*
============================================================================
Name : 18b.c
Author : Sejal Khandelwal
Description :  	Write a program to perform Record locking. 
		a. Implement write lock
		b. Implement read lock  
Date: 8th Sep, 2023.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

struct{
        int train_num;
        int ticket_count;
}db;
int main(){
        int fd,input;
        fd=open("record.txt",O_RDWR);
        printf("select Train number (1,2,3..): \n");
        scanf("%d",&input);

        struct flock lock;
        lock.l_type=F_WRLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=(input-1)*sizeof(db);
        lock.l_len=sizeof(db);
        lock.l_pid=getpid();

        //reading value of ticket number
        lseek(fd,(input-1)*sizeof(db),SEEK_SET);
        read(fd,&db,sizeof(db));
        printf("Before Entering into the critical section\n");

        fcntl(fd,F_SETLKW,&lock);
        printf("Ticket number: %d\n",db.ticket_count);
        db.ticket_count++;
        lseek(fd,-1*sizeof(db),SEEK_CUR);
        write(fd,&db,sizeof(db));
        printf("To book Ticket, Press Enter: \n");
        getchar();
        getchar();
        lock.l_type=F_UNLCK;
        fcntl(fd,F_SETLK,&lock);
        printf("Booked\n");
        return 0;
}
