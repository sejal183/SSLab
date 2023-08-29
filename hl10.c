#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd=open("employee_records.csv",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	if(fd== -1){
		printf("error");
		return 1;
	}
	char content[10];
	printf("enter the contents: ");
	scanf(" %[^\n]",content);
	write(fd,content,10);
	lseek(fd,10L,SEEK_END);
	write(fd,content,10);
	int curr=lseek(fd,0,SEEK_CUR);
	printf("the current offset value: %d \n",curr);
	return 0;
}
