#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main() {
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        close(pipe_fd[1]);

        char message[100];
        ssize_t bytes_read = read(pipe_fd[0], message, sizeof(message));
        if (bytes_read == -1) {
            perror("Read from pipe failed");
            return 1;
        }
        close(pipe_fd[0]);

        printf("Child process received: %s\n", message);
    } else {
        close(pipe_fd[0]);

        char message[] = "Hello, pipe!";
        ssize_t bytes_written = write(pipe_fd[1], message, strlen(message) + 1);
        if (bytes_written == -1) {
            perror("Write to pipe failed");
            return 1;
        }
        close(pipe_fd[1]);

        wait(NULL);

        printf("Parent process sent: %s\n", message);
    }

    return 0;
}

