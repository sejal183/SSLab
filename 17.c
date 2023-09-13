/*
============================================================================
Name : 17.c
Author : Sejal Khandelwal
Description: 	Write a program to simulate online ticket reservation. Implement write lock
		Write a program to open a file, store a ticket number and exit. 
		Write a separate program, to open the file, implement write lock, read the ticket number, 
		increment the number and print the new ticket number then close the file.
   
Date: 8th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    struct {
        int ticket_no;
    } db;
    struct flock lock;
    int fd;
    
    fd = open("db", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    if (read(fd, &db, sizeof(db)) != sizeof(db)) {
        db.ticket_no = 0;
        lseek(fd, 0, SEEK_SET);
        write(fd, &db, sizeof(db));
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before entering into critical section\n");
    fcntl(fd, F_SETLKW, &lock);

    lseek(fd, 0, SEEK_SET);
    read(fd, &db, sizeof(db));
    printf("Current ticket number: %d\n", db.ticket_no);
    db.ticket_no++;
    printf("%d \n", db.ticket_no);
    lseek(fd, 0, SEEK_SET);
    write(fd, &db, sizeof(db));

    printf("Inside the critical section....\n");
    printf("Enter to unlock...\n");
    getchar();

    lock.l_type = F_UNLCK;
    printf("Unlocked\n");
    fcntl(fd, F_SETLK, &lock);
    
    printf("Finish\n");

    close(fd);

    return 0;
}

