#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main() {
    const char* filename = "employee_records.csv"; // Replace with your filename
    int fd_original, fd_dup, fd_dup2, fd_fcntl;

    // Open the file for appending
    fd_original = open(filename, O_WRONLY | O_APPEND);
    if (fd_original == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor using dup
    fd_dup = dup(fd_original);

    // Duplicate the file descriptor using dup2
    fd_dup2 = dup2(fd_original, 5); // Using a specific descriptor number

    // Duplicate the file descriptor using fcntl
    fd_fcntl = fcntl(fd_original, F_DUPFD, 0);

    // Append data using original descriptor
    const char* data = "Appended using original descriptor.\n";
    write(fd_original, data, strlen(data));

    // Append data using duplicated descriptors
    const char* data_dup = "Appended using dup descriptor.\n";
    write(fd_dup, data_dup, strlen(data_dup));

    const char* data_dup2 = "Appended using dup2 descriptor.\n";
    write(fd_dup2, data_dup2, strlen(data_dup2));

    const char* data_fcntl = "Appended using fcntl descriptor.\n";
    write(fd_fcntl, data_fcntl, strlen(data_fcntl));

    // Close all descriptors
    close(fd_original);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    return 0;
}

