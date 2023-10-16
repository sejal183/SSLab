/*
 * ============================================================================
 Name : 24.c
 Author : Sejal Khandelwal
 Description : Write a program to create a message queue and print the key and message queue id. 
 Date: 10th OCT, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int msqid;
    key_t key;  

    // Generate a unique key for the message queue
    key = ftok("/home/ubuntu22/sslab/hl2/24", 'A');

    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue with read and write permissions
    msqid = msgget(key, IPC_CREAT | 0666);

    if (msqid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue Key: 0x%x\n", key);
    printf("Message Queue ID: %d\n", msqid);

    return 0;
}

