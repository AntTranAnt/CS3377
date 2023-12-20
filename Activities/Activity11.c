#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//global variables, can be accessed by all threads!
int limit = 0;
int counter = 0;

//return type and parameter type dictated by thread craetion mechanism
//void * means pointer to memory, but have no idea what data type it is pointing to
void * counting()
{
    int i = 0;
    for (i = 0; i < limit; i++) {
        counter++;
    }
}


int main()
{
    pthread_t tid0,tid1;
    int iret1=0, iret2=0;
    printf("\n Enter the value of limit");
    scanf("%d",&limit);
    //limit = 10;//atoi(argv[1]); //math table upper limit

    //create independent threads each of which will execute function
    iret1=pthread_create(&tid0, NULL, counting, NULL);
    iret2=pthread_create(&tid1, NULL, counting, NULL); 

    printf("\n Thread 1 returns: %d", limit);
    printf("\n Thread 2 returns: %d", limit);
    //wait till all threads are complete before main
    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);
    printf("\n %d * 2 = %d\n", limit, counter);
    exit(0);
}