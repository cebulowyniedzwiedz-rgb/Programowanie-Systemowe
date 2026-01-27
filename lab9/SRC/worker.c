#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "worker.h"

void* worker(void* arg) {
    WorkerArgs* args = (WorkerArgs*)arg;
    int in_fd = args->read_fd;
    int out_fd = args->write_fd;
    
    free(args);

    char input[256];

    while (1) {
        int n = read(in_fd, input, 256);
        if (n <= 0) break;

        if (strcmp(input, "exit") == 0) break;

        if (strlen(input) > 0) {
            input[0] = 'X';
        }

        write(out_fd, input, strlen(input) + 1);
    }
    return NULL;
}

