
/*
============================================================================
Name : 11.c
Author : Sejal Khandelwal
Description : 	Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and 
		check whether the file is updated properly or not.
		a. use dup 
		b. use dup2 
		c. use fcntl  
Date: 8th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void appendDescriptorToFile(int fd, char *descriptorType) {
    char descriptor_str[20];
    snprintf(descriptor_str, sizeof(descriptor_str), "%s %d\n",descriptorType, fd);

    if (write(fd, descriptor_str, strlen(descriptor_str)) == -1) {
        perror("Error writing descriptor");
        exit(1);
    }
}

int main() {
    const char *filename = "testfile.txt";

    int original_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (original_fd == -1) {
        perror("Error opening file");
        return 1;
    }
   
    int dup_fd = dup(original_fd);

    
    int dup2_fd = dup2(original_fd, 3);

    int fcntl_fd = fcntl(original_fd, F_DUPFD, 0);

    appendDescriptorToFile(original_fd, "Original fd: ");
    appendDescriptorToFile(dup_fd,"Duplicate fd: ");
    appendDescriptorToFile(dup2_fd,"Duplicate fd 2:" );
    appendDescriptorToFile(fcntl_fd, "Fcntl: ");

    close(original_fd);
    close(dup_fd);
    close(dup2_fd);
    close(fcntl_fd);

    return 0;
}

