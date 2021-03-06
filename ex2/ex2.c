// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// they can both access it and both write to the file.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    FILE *textFile = fopen("text.txt", "w+");

    pid_t pid = fork();

    if (pid == 0) //child process
    {
        fprintf(textFile, "Im the child...");
    }
    else
    {
        wait(NULL);
        fprintf(textFile, "Im the parent...");
    }

    return 0;
}
