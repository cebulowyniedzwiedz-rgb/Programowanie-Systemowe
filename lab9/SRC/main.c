#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "server.h"
#include "worker.h"

int main() {
    pthread_t t;
    int fd1[2], fd2[2];

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        return 1;
    }

    WorkerArgs* args = malloc(sizeof(WorkerArgs));
    if (!args) return 1;

    args->read_fd = fd1[0];
    args->write_fd = fd2[1];

    if (pthread_create(&t, NULL, worker, args) != 0) {
        free(args);
        return 1;
    }

    server(fd1[1], fd2[0]);

    close(fd1[1]);
    close(fd2[0]);
    pthread_join(t, NULL);
    close(fd1[0]);
    close(fd2[1]);

    return 0;
}
