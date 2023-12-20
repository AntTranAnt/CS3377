#include <stdio.h>
#include <pthread.h>

//global declarations
int incremento = 0;
pthread_mutex_t mutexLock;

//function to increment a shared value
void *incrementVar() {
pthread_mutex_lock(&mutexLock);
incremento = incremento + 1000;
printf("Mutex lock -> Thread %ld incremented variable to %d -> Mutex unlock\n", (long) pthread_self(), incremento);
pthread_mutex_unlock(&mutexLock);
return 0;
}

int main(int argc, char const *argv[])
{
pthread_t process1, process2;
pthread_mutex_init(&mutexLock, NULL);

//create 2 processes
if (pthread_create(&process1, NULL, &incrementVar, NULL) != 0) {
return 1;
}
if (pthread_create(&process2, NULL, &incrementVar, NULL) != 0) {
return 1;
}

//join threads
if (pthread_join(process1, NULL) != 0) {
return 1;
}
if (pthread_join(process2, NULL) != 0) {
return 1;
}

pthread_mutex_destroy(&mutexLock);

return 0;
}
