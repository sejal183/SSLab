/*
============================================================================
Name : 21.c
Author : Sejal Khandelwal
Description : Write a program, call fork and print the parent and child process id.  
Date: 8th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t pp,cp;
	if(fork()){
		pp = getpid();
		printf("Parent's process id: %d\n",pp);
	}
	else{
		cp = getpid();
		printf("Child's process id: %d",cp);
	}
	return 0;
}
