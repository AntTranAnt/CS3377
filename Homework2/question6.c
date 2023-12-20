#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int inputRec = 0;

void * timer() {
sleep(5);
pthread_mutex_lock(&mutex);
inputRec = 0;
pthread_mutex_unlock(&mutex);
return 0;
}

void * input() {
printf("Enter a number: ");
int inn;
scanf("%d", &inn);
pthread_mutex_lock(&mutex);
inputRec = 1;
pthread_mutex_unlock(&mutex);
return 0;
}

int main() {
pthread_t processTimeout;
pthread_t processInput;

if (pthread_create(&processTimeout, NULL, timer, NULL) != 0) {
return 1;
}
if (pthread_create(&processInput, NULL, input, NULL) != 0) {
return 1;
}

pthread_join(processTimeout, NULL);

pthread_mutex_lock(&mutex);
if (inputRec == 1) {
printf("Input received.\n");
} else {
printf("\nTimout!!\n");
}
pthread_mutex_unlock(&mutex);
return 0;
}

