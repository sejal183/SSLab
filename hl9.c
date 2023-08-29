#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
        int inode, no_of_hardlink;
        int fd=open("employee_records.csv", O_RDWR);

        if(fd<0){
                printf("Error opening the file");
        }
        struct stat file_stat;
        int result=fstat(fd,&file_stat);
        if (result<0){
                printf("Error getting file stat.");
        }
        inode=file_stat.st_ino;
        printf("Node of the File: %d \n", inode);
        no_of_hardlink=file_stat.st_nlink;
        printf("No of hardlink: %d \n",no_of_hardlink);
        int uid=file_stat.st_uid;
        printf("User Id of the file owner: %d \n",uid);
        int gid=file_stat.st_gid;
        printf("Group Id of the file owner: %d \n",gid);
        int size=file_stat.st_size;
        printf("Total size of the File: %d \n",size);
        int blocksize=file_stat.st_blksize;
        printf("Blocksize: %d \n",blocksize);
        int no_of_blocks=file_stat.st_blocks;
        printf("No of blocks: %d \n",no_of_blocks);
        int last_time_access=file_stat.st_atime;
        printf("Last access time: %d \n", last_time_access);
        int last_time_modified=file_stat.st_mtime;
        printf("Last time modified: %d \n", last_time_modified);
        int last_time_statuschange=file_stat.st_ctime;
        printf("time of last status change: %d \n",last_time_statuschange);
	return 0;
}
