//Anthony Tran
//Program to implement processes to print sum of fibonacci sequence up to n

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int sum = 0;
int fib[100];

//recursive function to generate fibonocci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

//helper function to call fibonacci and write to parent
void fibonacciHelper(int n, int writeNum) {
    for (int i = 0; i <= n; i++) {
        fib[i] = fibonacci(i);
    }
    write(writeNum, fib, sizeof(fib));
}

int main(int argc, char *argv[]) {
    int fibNum = atoi(argv[1]);

    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) { //child
        close(fd[0]);
        fibonacciHelper(fibNum, fd[1]);
        close(fd[1]);
    } else { //parent
        close(fd[1]);
        read(fd[0], fib, sizeof(fib));
        for (int i = 0; i <= fibNum; i++) {
            printf("%d ", fib[i]);
        }
        printf("\n");
        close(fd[0]);
    }
    return 0;
}