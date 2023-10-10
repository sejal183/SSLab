
/*
============================================================================
Name : 4.c
Author : Sejal Khandelwal
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.  
Date: 8th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	const char *f1="fourth.txt";
	int frd=open(f1,O_RDWR);
	if(frd==-1)
	{
		perror("error in reading mode");
			return 1;
	}
	else
	{
		printf("file opened successfully in RM   with fd %d\n       ",frd);
		
		close(frd);
	}

	int fwd=open(f1,O_RDWR | O_EXCL);
	if(fwd==-1)
	{		
	if(errno==EEXIST){
	   perror("File already exist(O_EXCL flag)");
	}

	else{
	  error("Error opening file with O_EXCL flag");
	}
	}
	else
	{printf("File opened successfully  with O_EXCL flag  %d \n   ",fwd);
		close(fwd);
	}
	return 0;
}


