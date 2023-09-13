/*
============================================================================
Name : 7.c
Author : Sejal Khandelwal
Description : Write a program to copy file1 into file2 ($cp file1 file2).  
Date: 8th Sep, 2023.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	if(argc!=3)
		{
		printf("You are useless");
		return 0;
	}
          int fd_read=open(argv[1],O_RDONLY);
	  int fd_write=open(argv[2],O_WRONLY|O_CREAT,0644);
	  if(fd_write==-1||fd_read==-1)
		  printf("Useless");
	  while(1)
	  {
	  char buf;
	 int char_read=read(fd_read,&buf,1);
	 if (char_read==0)
		break;
	 int char_written=write(fd_write,&buf,1);
	  }
	  int fd_read_close=close(fd_read);
	  int fd_write_close=close(fd_write);

	  if(fd_read_close==-1||fd_write_close==-1)
		  printf("Totally useless");
	return 0;
}


