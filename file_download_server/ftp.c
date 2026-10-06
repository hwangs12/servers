#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "num_cores.h"

void *say_hi (void *args);

int main(int argc, char *argv[]) {
    int num_cores = getNumberOfCores();

    pthread_t *t = malloc(num_cores * sizeof(pthread_t));
    pthread_attr_t a;

    for (int i = 0; i < num_cores; i++) {
        pthread_attr_init(&a);
        pthread_create(&t[i], &a, say_hi, (void*) &i);
    }
    for (int i = 0; i < num_cores; i++) {
        pthread_join(t[i], NULL);
    }
}

void *say_hi (void *args) {
    int *i = (int*) args;
    printf("hello world from thread %d!\n", *i);
    return NULL;
}
