#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
int main(){
	int fd=open("employee_records.csv",O_RDONLY);
	int flags,accessMode;
	flags=fcntl(fd,F_GETFL);
	if(flags==-1)
		exit(1);
	printf("opening mode %d \n",flags);
	return 0;
}

