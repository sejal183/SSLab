/*
============================================================================
Name : 25.c
Author : Sejal Khandelwal
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).   
Date: 8th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pids[3];
    int status;
    for (int i = 0; i < 3; i++) {
        child_pids[i] = fork();
        
        if (child_pids[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pids[i] == 0) {
            printf("Child %d with PID %d is running\n", i + 1, getpid());
            sleep(2);
            exit(EXIT_SUCCESS);
        }
    }
    printf("Parent process with PID %d is waiting for Child 2 to finish\n", getpid());
    pid_t finished_pid = waitpid(child_pids[1], &status, 0);

    if (finished_pid == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status)) {
        printf("Child %d with PID %d has finished with status %d\n",
               2, finished_pid, WEXITSTATUS(status));
    }
    printf("Parent process continues\n");
    return 0;
}

