/*
============================================================================
Name : 27.c
Author : Sejal Khandelwal
Description : 	Write a program to execute ls -Rl by the following system calls 
		a. execl
		b. execlp
		c. execle 
	       	d. execv 
		e. execvp

Date: 8th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Select an exec function to execute ls -Rl:\n");
    printf("1. execl\n");
    printf("2. execlp\n");
    printf("3. execle\n");
    printf("4. execv\n");
    printf("5. execvp\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nUsing execl:\n");
            execl("/bin/ls", "ls", "-Rl", NULL);
            break;
        case 2:
            printf("\nUsing execlp:\n");
            execlp("ls", "ls", "-Rl", NULL);
            break;
        case 3:
            printf("\nUsing execle:\n");
            char* envp[] = {NULL}; // No environment variables
            execle("/bin/ls", "ls", "-Rl", NULL, envp);
            break;
        case 4:
            printf("\nUsing execv:\n");
            char* argv[] = {"ls", "-Rl", NULL};
            execv("/bin/ls", argv);
            break;
        case 5:
            printf("\nUsing execvp:\n");
            char* argvp[] = {"ls", "-Rl", NULL};
            execvp("ls", argvp);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

