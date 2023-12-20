#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex1, mutex2;

void * processFor1() {
    pthread_mutex_lock(&mutex1);
    pthread_mutex_lock(&mutex2);
    printf("Process 1 is running\n");
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return 0;
}

void * processFor2() {
    pthread_mutex_lock(&mutex1);
    pthread_mutex_lock(&mutex2);
    printf("Process 2 is running\n");
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return 0;
}

int main(int argc, char const *argv[])
{
pthread_t process1, process2;
pthread_mutex_init(&mutex1, NULL);
pthread_mutex_init(&mutex2, NULL);

if (pthread_create(&process1, NULL, &processFor1, NULL) != 0) {
return 1;
}
if (pthread_create(&process2, NULL, &processFor2, NULL) != 0) {
return 1;
}

if (pthread_join(process1, NULL) != 0) {
printf("Process 1 cant join: DEADLOCKED!!");
return 1;
}
if (pthread_join(process1, NULL) != 0) {
printf("Process 2 cant join: DEADLOCKED!!");
return 1;
}

pthread_mutex_destroy(&mutex1);
pthread_mutex_destroy(&mutex2);
return 0;
}
