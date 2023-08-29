#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input from STDIN for 10 seconds...\n");

    int ready_fds = select(STDIN_FILENO + 1, &fds, NULL, NULL, &timeout);

    if (ready_fds == -1) {
        perror("Error in select");
        return 1;
    } else if (ready_fds == 0) {
        printf("No input available within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            printf("Input is available within 10 seconds!\n");
        } else {
            printf("Unexpected error.\n");
        }
    }

    return 0;
}

