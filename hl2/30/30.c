/*
 * ============================================================================
 Name : 30.c
 Author : Sejal Khandelwal
 Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
 Date: 10th OCT, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Create a key for the shared memory (you can use an existing key or generate a unique one).
    key_t key = ftok("/tmp", 'a');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    // Create a shared memory segment with read-write permissions.
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment with read-write permissions.
    char *shmaddr = (char *)shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1) {
        perror("shmat");
        return 1;
    }

    // Write data to the shared memory.
    strcpy(shmaddr, "Hello, Shared Memory!");

    printf("Data in shared memory: %s\n", shmaddr);

    // Detach the shared memory.
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
    }

    // Attach the shared memory with read-only permissions (O_RDONLY).
    shmaddr = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (shmaddr == (void *)-1) {
        perror("shmat (read-only)");
        return 1;
    }

    // Attempt to overwrite the data (this should result in an error).
    strcpy(shmaddr, "Trying to overwrite!");

    // Detach the shared memory again.
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
    }

    // Remove the shared memory segment.
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl (remove)");
    }

    printf("Shared memory removed.\n");

    return 0;
}

