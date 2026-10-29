#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "cores.h"

void* thread_function(void* arg) {
    int thread_num = *((int *)arg);
    printf("[thread %d] Hello from the detached thread!\n", thread_num);
    return NULL;
}

int main() {
    int num_cpus = get_core_count();   
    printf("There are %d cores\n", num_cpus);
    pthread_t* threads = malloc(sizeof(pthread_t)*num_cpus-1);
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    for (int i = 0; i < num_cpus - 1; i++) {
        if (pthread_create(&threads[i], &attr, thread_function, (void*)&i) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    pthread_attr_destroy(&attr);

    return 0;
}
