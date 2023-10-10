
/*
============================================================================
Name : 13.c
Author : Sejal Khandelwal
Description :	Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to 
		verify whether the data is available within 10 seconds or not (check in $man 2 select).   
Date: 8th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int ready;


    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);


    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input from STDIN for up to 10 seconds...\n");


    ready = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (ready == -1) {
        perror("select");
        return 1;
    } else if (ready == 0) {
        printf("No data received within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("Data is available within 10 seconds.\n");
            
            // Now you can read the data from stdin if you want
            char input[256];
            fgets(input, sizeof(input), stdin);
            printf("You entered: %s", input);
        }
    }

    return 0;
}

