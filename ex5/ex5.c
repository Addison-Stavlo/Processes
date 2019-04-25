// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("im child\n");
        write(fd[1], msg1, sizeof(char) * MSGSIZE);
        write(fd[1], msg2, sizeof(char) * MSGSIZE);
        write(fd[1], msg3, sizeof(char) * MSGSIZE);
    }
    else
    {
        waitpid(pid, NULL, 0);

        char buf[MSGSIZE];

        printf("im parent\n");
        read(fd[0], buf, sizeof buf);
        printf("message 1: %s\n", buf);
        read(fd[0], buf, sizeof buf);
        printf("message 2: %s\n", buf);
        read(fd[0], buf, sizeof buf);
        printf("message 3: %s\n", buf);
    }

    return 0;
}
