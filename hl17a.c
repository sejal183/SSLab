#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int i,fd;
	struct{
		int train_num;
		int ticket_count;
	      } db[3];

	for(i=0;i<3;i++){
		db[i].train_num=i+1;
		db[i].ticket_count=0;
	}
	fd = open("hl17.txt",O_RDWR);
	write(fd,db,sizeof(db));
	close(fd);
}


