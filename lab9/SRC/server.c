#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

void server(int write_fd, int read_fd) {
    char buffer[256];
    char result[256];
    int n;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        
        n = read(0, buffer, 255);
        if (n <= 0) break;

        write(write_fd, buffer, strlen(buffer) + 1);

        if (strcmp(buffer, "exit") == 0) break;

        read(read_fd, result, 256);

        write(1, result, strlen(result));
    }
}
