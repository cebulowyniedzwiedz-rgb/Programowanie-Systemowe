#ifndef PARENT_H
#define PARENT_H
#include <semaphore.h>
void worker(char *ptr, sem_t *sem_write, sem_t *sem_read);

#endif
