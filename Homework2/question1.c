#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
pid_t childProcess;
childProcess = fork(); //create child process

if(childProcess == 0) {
//child process
printf("Child process id: %d\n", getpid());
//creates new process group with groupid of child process
setpgid(0,getpid());
printf("Created new group with child process...\n");
printf("Child process group id: %d\n",getpgrp());
} else {
//parent process
printf("Parent process id: %d\n", getpid());
}

return 0;
}
