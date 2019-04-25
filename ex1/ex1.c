// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// they can both access it and change its value, somehow while sharing the same memory location??

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int x = 100;

    pid_t pid = fork();

    if (pid == 0) //child process
    {
        printf("child process x = %d at address %p\n", x, &x);
        x = 10;
        printf("child process now x = %d at address %p\n", x, &x);
    }
    else
    {
        printf("parent process x = %d at address %p\n", x, &x);
        x = 1000;
        printf("parent process now x = %d at address %p\n", x, &x);
    }

    printf("x = %d at address %p\n", x, &x);

    return 0;
}
