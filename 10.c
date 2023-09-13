/*
============================================================================
Name : 10.c
Author : Sejal Khandelwal
Description : 	Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
		a. check the return value of lseek
		b. open the file with od and check the empty spaces in between the data.   
Date: 8th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   int fd = open("sample.txt",O_RDWR|O_CREAT | O_TRUNC, 0666);
   if(fd== -1)
   {
           perror("error in opening file");
           return 1;

    }
   const char d1[]="0123456789";
   ssize_t byt= write(fd,d1,sizeof(d1)-1);

   if(byt ==-1)
   {
           perror("error writting data");
           close(fd);
           return 1;
   }

   off_t offset = lseek(fd, 10, SEEK_CUR);
   if(offset == -1)
   {
           perror("error seeking");
           close(fd);
           return 1;
   }

   //write more 10B
   const char d2[]="Hello World";
   byt = write(fd, d2, sizeof(d2) -1);
   if(byt==-1)
   {
           perror("error writing");
           close(fd);
           return 1;
   }
   close(fd);
   printf("lseek returned offset: %ld\n", offset);
   return 0;
}
