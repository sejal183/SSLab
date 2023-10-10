#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    // Get the maximum number of files that can be opened within a process
    long maxOpenFiles = sysconf(_SC_OPEN_MAX);

    if (maxOpenFiles == -1) {
        perror("sysconf");
        return 1;
    }

    // Get the size of a pipe (circular buffer)
    long pipeSize = sysconf(_SC_PIPE_BUF);

    if (pipeSize == -1) {
        perror("sysconf");
        return 1;
    }

    printf("Maximum number of files that can be opened within a process: %ld\n", maxOpenFiles);
    printf("Size of a pipe (circular buffer): %ld bytes\n", pipeSize);

    return 0;
}

