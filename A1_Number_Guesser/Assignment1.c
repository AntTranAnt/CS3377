//Anthony Tran
//axt220037
//3377.005
//Program to make a guessing game.
//Default settings, the program generates a random number between -100 and 100.
//The program then ask the user to guess the random number, while also giving hints
//on either the number guessed is lower or higher than the actual number.
//The program also keeps track of the number of guess, which is returned as the player's score.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//generates a random number inclusive between min and max
int randomNumberGenerator(int min, int max) {
    srand(time(NULL));
    int random = (rand() % (max + 1 - min)) + min;
    return random;
}

//method to give hint of higher or lower to user
void giveHint(int guess, int random) {
    if (guess > random) {
        printf("High Guess\n");
    } else if (guess < random) {
        printf("Low Guess\n");
    }
}

int main()
{
    int guess;
    int score = 0;
    int min = -100;
    int max = 100;
    int random = randomNumberGenerator(min, max);
    int maxScore = 7;
    char username[101];
    FILE * filePointer;
    bool notGuessed = true;

    //open new or preesxisting file
    filePointer = fopen("game_report.txt", "a");

    //print introduction and ask for username
    printf("Welcome to the guessing game.\n");
    printf("Enter your Username: ");
    scanf("%100s", username);
    printf("%s, ", username);
    printf("you will have %d tries to guess a number between %d and %d.\n", maxScore, min, max);
    printf("Guess the number: ");

    //loop through attempts or until user guesses properly.
    while (notGuessed && score < maxScore) {
        scanf("%d", &guess);
        score += 1;
        if (guess != random && score < maxScore) {
            printf("Wrong number, guess again. ");
            giveHint(guess, random);
        } else if (guess == random) {
            notGuessed = false;
            printf("Correct, you got it in %d guesses!\n", score);
        }
    }

    //check if manage to guess and print to file
    if (notGuessed) {
        printf("Sorry, you did not manage to guess within %d tries.\n", maxScore);
        printf("The correct number was: %d", random);
        fprintf(filePointer, "Username: %s, Score failed\n", username);
    } else {
        fprintf(filePointer, "Username: %s, Score %d\n", username, score);
    }

    //close file
    fclose(filePointer);
    
    return 0;
}