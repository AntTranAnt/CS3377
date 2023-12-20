#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

int incremento = 0;
sem_t sem;

//function to increment incremento and print variable using semaphores
void * incrementing() {
sem_wait(&sem);
incremento = incremento + 1000;
printf("Thread %ld incremented variable to %d\n", (long) pthread_self(), incremento);
sem_post(&sem);
return 0;
}

int main(int argc, char const *argv[])
{
pthread_t process1, process2;
sem_init(&sem, 0, 1);
//create threads
if (pthread_create(&process1, NULL, &incrementing, NULL) != 0) {
return 1;
}
if (pthread_create(&process2, NULL, &incrementing, NULL) != 0) {
return 1;
}

//join threads
if (pthread_join(process1, NULL) != 0) {
return 1;
}
if (pthread_join(process2, NULL) != 0) {
return 1;
}
sem_destroy(&sem);
return 0;
}
