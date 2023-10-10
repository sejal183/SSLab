#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_PATH "myfifo" // Replace with your desired FIFO name

int main() {
    int fd;
    char message[256];

    // Create or open the FIFO for writing
    mkfifo(FIFO_PATH, 0666);
    fd = open(FIFO_PATH, O_WRONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter a message (or type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);

        // Remove newline character from the message
        message[strlen(message) - 1] = '\0';

        if (strcmp(message, "exit") == 0) {
            break;
        }

        write(fd, message, strlen(message));
    }

    close(fd);

    return 0;
}

