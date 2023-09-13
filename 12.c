
/*
============================================================================
Name : 12.c
Author : Sejal Khandelwal
Description : Write a program to find out the opening mode of a file. Use fcntl.   
Date: 8th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

void checkAccessMode(int flags) {
    int access_mode = flags & O_ACCMODE;

    if (access_mode == O_RDONLY) {
        printf("File opened in read-only mode.\n");
    } else if (access_mode == O_WRONLY) {
        printf("File opened in write-only mode.\n");
    } else if (access_mode == O_RDWR) {
        printf("File opened in read-write mode.\n");
    } else {
        printf("Unknown file access mode.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <flags>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int flags = atoi(argv[2]);

    int fd = open(filename, flags);
    if (fd == -1) {
        perror("Error opening file");
        return 2;
    }

    printf("Opening mode for %s:\n", filename);
    checkAccessMode(fcntl(fd, F_GETFL));

    close(fd);

    return 0;
}


