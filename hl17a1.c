#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
struct{
	int train_num;
	int ticket_count;
      } db;
int main(){
	int fd,input;
	fd = open("hl17.txt",O_RDWR);
	printf("select train number (1,2,3):\n");
	scanf("%d",&input);
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (input-1)*sizeof(db);
	lock.l_len = sizeof(db);
	lock.l_pid = getpid();

	lseek(fd,(input-1)*sizeof(db),SEEK_SET);
	read(fd,&db,sizeof(db));
	printf("Before Entering into the critical section\n");

	fcntl(fd,F_SETLKW,&lock);
	printf("Ticket Number: %d\n",db.ticket_count);
	db.ticket_count++;
	lseek(fd,-1*sizeof(db),SEEK_CUR);
	write(fd,&db,sizeof(db));
	printf("To book ticket, press enter: \n");
	getchar();
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Booked\n");
        }

