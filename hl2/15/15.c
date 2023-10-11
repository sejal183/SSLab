/*
============================================================================
Name : 15
Author :Sejal Khandelwal
Description : Write a simple program to send some data from parent to the child process.
Date: 10-october-2023
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
int main(){
	int fd[2];
	pipe(fd);
	char message = "Hello from parent";
	pid_t pid = fork();
	if(pid == 0){
		close(fd[1]);
		char message[100];
		ssize_t r = read(fd[0],message,sizeof(message));
		if(r==-1) {
			perror("Read failed");
			return -1;
		}
		close(fd[0]);
		printf("child recieved%s\n",message);
	}
	else{
		close(fd[0]);
		char message[] = "HEllo from parent";
		ssize_t w = write(fd[1],message,sizeof(message));
		if(w==-1){
			perror("Write failed");
			return -1;
		}
		close(fd[1]);
		wait(NULL);
		printf("Parent sent%s\n" ,message);
	}

}
