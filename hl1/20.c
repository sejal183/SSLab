/*
============================================================================
Name : 20.c
Author : Sejal Khandelwal
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 8th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int priority;
    priority = getpriority(PRIO_PROCESS, getpid());
    if (priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("Current priority: %d\n", priority);
    int new_priority = priority - 10;
    if (nice(new_priority) == -1) {
        perror("Error setting new priority");
        return 1;
    }

    printf("New priority: %d\n", getpriority(PRIO_PROCESS, getpid()));

    return 0;
}

