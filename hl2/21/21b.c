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

    // Open the FIFO for reading
    fd = open(FIFO_PATH, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        ssize_t bytesRead = read(fd, message, sizeof(message));

        if (bytesRead == -1) {
            perror("read");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Null-terminate the received data to treat it as a string
        message[bytesRead] = '\0';

        printf("Received message: %s\n", message);

        if (strcmp(message, "exit") == 0) {
            break;
        }
    }

    close(fd);

    return 0;
}

