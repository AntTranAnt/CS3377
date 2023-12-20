#include<stdio.h>
#include<unistd.h>
//Create 2 separate files for communication
//parent-->child, child--> parent
//parent to child -> abc
//child to parent -> xyz
int main()
{
int tochild[2], toparent[2];
//create single pipe

pipe(tochild);
printf("\n Parent fds : %d and %d\n", tochild[0], tochild[1]);
pipe(toparent);
printf("\n Child fds : %d and %d\n", toparent[0], toparent[1]);
if(fork()>0)
{
//Parent writes first "abc" on the pipe tochild and waits for reading until child writes
write(tochild[1], "abc", 4);
printf("\n Parent wrote to child %s", "abc");
//read it from pipe and display

char readback[4];
read(toparent[0], readback, 4);
printf("\n Parent reading from child :- %s%s\n", readback, readback);
//puts(readback);
printf("\n Parent process with process ID %d is done.", getpid());

}
else
{
//child process reads first then writes
char buffer[6];
read(tochild[0], buffer, 6);
printf("\n Child read from parent %s\n", buffer);
//puts(buffer);
write(toparent[1], "abc", 4);
printf("\n Child writing to parent %s\n", "abcabc");
printf("\n Child process with process ID %d is done.", getpid());
}
}
