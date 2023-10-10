/*
============================================================================
Name : 24.c
Author : Sejal Khandelwal
Description : Write a program to create an orphan process.  
Date: 8th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
  
int main()
{      
    int pid = fork();
  
    if (pid > 0){

       printf("In parent process");
       printf("child id    %d ",pid);
    }
  
    else if (pid == 0)
    {
        sleep(50);
        printf("In child process");
    }
  
    return 0;
}
