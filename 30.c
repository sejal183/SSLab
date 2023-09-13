/*
============================================================================
Name : 30.c
Author : Sejal Khandelwal
Description :  Write a program to run a script at a specific time using a Daemon process. 
Date: 8th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
	if(!fork()){
		printf("the child process with %d process id will be made the daemon process\n", getpid());
		umask(0);
        	pid_t pid, setid;
       		pid=getpid();
       		setid=setsid();
        	while(1){
                	time_t now= time(NULL);
                	struct tm *tm_info=localtime(&now);
                	if(tm_info->tm_hour==22 && tm_info->tm_min==38){
                        	printf("Time matched\n");
                        	break;
                	}
        	}
		exit(0);
	}
	else{
		printf("the parent process with %d process id is terminated\n", getpid());
		return 1;
	}
	return 0;

