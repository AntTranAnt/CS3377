#include <stdio.h>
#include <unistd.h>

//print using id from parent or child process.
void printFunction(int id) {
    if (id == 0) {
        printf("Print child ID: %d\n", id);
    } else {
        printf("Print parent ID: %d\n", id);
    }
}

int main()
{
    printf("Printing by ID: Main Process\n");
    
    //first fork
    pid_t id = fork();
    printFunction(id);

    //second fork
    pid_t id2 = fork();
    printFunction(id);
    
    //third fork
    pid_t id3 = fork();
    printFunction(id);

    return 0;
}