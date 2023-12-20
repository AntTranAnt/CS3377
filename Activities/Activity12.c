#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int score = 0;
int counter= 0;
void alarm_received(int signo) {
    printf("\nAlarm Received current score = %d", score);
    counter++;
    //re-register the signal
    signal(SIGALRM, alarm_received);
    if(counter < 3)
    alarm(20);
    else exit(0);
}
//function to congratulate user when they reach a score of 5
void achievedFive(int signo) {
    if (score >= 5) {
        printf("Goodjob, you've scored higher than 5!");
        signal(SIGUSR1, achievedFive);
    }
}

int main() {
    srand(time(NULL) + getpid() + getuid());
    signal(SIGALRM, alarm_received);
    signal(SIGUSR1, achievedFive);
    alarm(20);

    while(1) {
        //generate 2 two-digit numbers and ask user for the total.
        int num1 = rand() % 100;
        int num2 = rand() % 100;
        printf("\n%d + %d = ? ", num1, num2);
        int input = 0;
        scanf("%d", &input);
        if((num1+num2) == input) {
            score++;
            puts("Great!"); 
        } else {
            puts("Wrong.");
            printf("\nYour score is = %d", score);
        }
        //if score >= 5 raise signal to congratulate user
        if (score >= 5) {
            raise(SIGUSR1);
        }
    }
} 
