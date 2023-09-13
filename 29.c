/*
============================================================================
Name : 29.c
Author : Sejal Khandelwal
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).  
Date: 8th Sep, 2023.
============================================================================
*/

#define _GNU_SOURCE // Required for sched_getscheduler and sched_setscheduler
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0); // 0 indicates the current process
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(1);
    }

    printf("Current scheduling policy: ");

    switch (policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER (normal)\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    param.sched_priority = 99; // Set the priority (adjust as needed)
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
        exit(1);
    }

    printf("Modified scheduling policy to SCHED_RR\n");

    return 0;
}

