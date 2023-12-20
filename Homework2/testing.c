#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
       int fds[2];
       pipe(fds);
       printf("%d", fds[1]);
}