#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
//file descriptor for read and write
int pipeid[2];

//make a pipe
if(pipe(pipeid) == -1) {
printf("Error occured opening pipe\n");
return -1;
}

//create child process
int childid = fork();
if (childid == 0) {
//child process
close(pipeid[0]);
int input;
printf("Enter a number: ");
scanf("%d", &input);
write(pipeid[1], &input, sizeof(int));
close(pipeid[1]);
} else {
//parent process
close(pipeid[1]);
int output;
read(pipeid[0], &output, sizeof(int));
printf("Parent received message from child: %d\n", output);
close(pipeid[0]);
}
return 0;
}
