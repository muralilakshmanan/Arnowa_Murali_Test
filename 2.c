#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 6

void *threadFunc(void *arg) {
    int threadID = *(int *)arg;
    printf("Thread %d: Hello Arnowa This is Murali %d\n", threadID, threadID);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadArgs[NUM_THREADS];
    int result_code;

    
    for (int i = 0; i < NUM_THREADS; i++) {       // Create the threads
        threadArgs[i] = i;
        result_code = pthread_create(&threads[i], NULL, threadFunc, &threadArgs[i]);

        if (result_code != 0) {
            printf("Error creating thread %d. Code: %d\n", i, result_code);
            exit(-1);
        }

        
        if (i % 2 == 1) {                // Sleep for 10 seconds for every alternate thread
            sleep(10);
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}