/*
============================================================================
Name : 5.c
Author : Sejal Khandelwal
Description :  	Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor 
		table at /proc/pid/fd. 
Date: 8th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>

int main() {
	int file1 = creat("file1.txt",0644);
	int file2 = creat("file2.txt",0644);
	int file3 = creat("file3.txt",0644);
	int file4 = creat("file4.txt",0644);
	int file5 = creat("file5.txt",0644);
	while(1);
}
