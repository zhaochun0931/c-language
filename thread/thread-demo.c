#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define NUM_THREADS 4

void* thread_function(void* arg) {
    int thread_num = *(int*)arg;
    pid_t tid = syscall(SYS_gettid);  // Get the actual thread ID
    printf("[Thread %d] Started (TID: %d)\n", thread_num, tid);

    for (int i = 1; i <= 5; i++) {
        printf("[Thread %d] Iteration %d\n", thread_num, i);
        sleep(thread_num);  // Sleep different time per thread
    }

    printf("[Thread %d] Done\n", thread_num);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    printf("Main PID: %d\n", getpid());

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}
