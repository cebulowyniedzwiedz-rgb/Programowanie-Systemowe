#ifndef WORKER_H
#define WORKER_H

typedef struct {
    int read_fd;
    int write_fd;
} WorkerArgs;

void* worker(void* arg);

#endif
