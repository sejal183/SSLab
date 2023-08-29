#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* filename = "employee_records.csv";
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Set a write lock
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;  // Lock the entire file

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error setting write lock");
        return 1;
    }

    printf("Write lock acquired. Press Enter to release lock.\n");
    getchar();

    // Release the lock
    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error releasing lock");
        return 1;
    }

    close(fd);

    return 0;
}

