#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
int main() {
    int pipe_parent_to_child[2];
    int pipe_child_to_parent[2];
    pid_t pid;

    if (pipe(pipe_parent_to_child) == -1 || pipe(pipe_child_to_parent) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipe_parent_to_child[1]);
        close(pipe_child_to_parent[0]);

        char message[100];

        while (1) {
            if (read(pipe_parent_to_child[0], message, sizeof(message)) == -1) {
                perror("Read from parent failed");
                exit(EXIT_FAILURE);
            }

            if (strcmp(message, "exit\n") == 0) {
                break;
            }

            printf("Child received: %s", message);

            // Process the message (e.g., convert to uppercase)
            int len = strlen(message);
            for (int i = 0; i < len; i++) {
                message[i] = toupper(message[i]);
            }

            if (write(pipe_child_to_parent[1], message, len) == -1) {
                perror("Write to parent failed");
                exit(EXIT_FAILURE);
            }
        }

        close(pipe_parent_to_child[0]);
        close(pipe_child_to_parent[1]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipe_parent_to_child[0]);
        close(pipe_child_to_parent[1]);

        char message[100];

        while (1) {
            printf("Enter a message for the child (or 'exit' to quit): ");
            fgets(message, sizeof(message), stdin);

            if (write(pipe_parent_to_child[1], message, strlen(message)) == -1) {
                perror("Write to child failed");
                exit(EXIT_FAILURE);
            }

            if (strcmp(message, "exit\n") == 0) {
                break;
            }

            if (read(pipe_child_to_parent[0], message, sizeof(message)) == -1) {
                perror("Read from child failed");
                exit(EXIT_FAILURE);
            }

            printf("Parent received: %s", message);
        }

        close(pipe_parent_to_child[1]);
        close(pipe_child_to_parent[0]);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    return 0;
}

