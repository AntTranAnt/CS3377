//Anthony Tran
//Program to implement threads to print sum of fibonacci sequence up to n

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int sum = 0;
int fib[100];
//function that recursively creates threads to calculate fibonacci sum
void * fibonacci(void * fibNum) {
    int n = *(int *)fibNum;

    if (n <= 1) {
        sum += n;
        fib[n] = n;
        pthread_exit(NULL);
    } else {
        pthread_t th1, th2;
        int th_1 = n - 1;
        int th_2 = n - 2;
        pthread_create(&th1, NULL, &fibonacci, (void*) &th_1);
        pthread_create(&th2, NULL, &fibonacci, (void*) &th_2);
        pthread_join(th1, NULL);
        pthread_join(th2, NULL);

        fib[n] = fib[n-1] + fib[n-2];

        pthread_exit(NULL);
    }
}

int main(int argc, char *argv[]) {
    pthread_t th;
    int fibNum = atoi(argv[1]);

    pthread_create(&th, NULL, &fibonacci, (void*) &fibNum);
    pthread_join(th, NULL);

    for (int i = 0; i <= fibNum; i++) {
        printf("%d ", fib[i]);
    }

    printf("\nFibonacci %d: %d\n", fibNum, sum);

    return 0;
}
