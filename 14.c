/*
============================================================================
Name : 14.c
Author : Sejal Khandelwal
Description :  	Write a program to find the type of a file.
		a. Input should be taken from command line.
		b. program should be able to identify any type of a file.   
Date: 8th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];

    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        perror("Error getting file information");
        return 1;
    }

    if (S_ISREG(file_stat.st_mode)) {
        printf("%s is a regular file.\n", filename);
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("%s is a directory.\n", filename);
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("%s is a symbolic link.\n", filename);
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("%s is a FIFO/pipe.\n", filename);
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("%s is a socket.\n", filename);
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("%s is a block special file.\n", filename);
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("%s is a character special file.\n", filename);
    } else {
        printf("%s is of an unknown type.\n", filename);
    }

    return 0;
}

