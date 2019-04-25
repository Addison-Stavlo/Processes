// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

// after "exec" - the "l" vs "v" specifies a list vs an array of arguments.
// after l or v - p allows you to search for the process in PATH
// after l or v (and optional "p") - e allows you to specify a new environment

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here
    pid_t pid = fork();

    if (pid == 0)
    {
        // // for "l" type list args followed by NULL
        execl("/bin/ls", "ls", NULL);
        // execle("/bin/ls", "ls", NULL, NULL);
        // execlp("/bin/ls", "ls", NULL);

        // // for "v" type (need array)
        // char *myargs[2];
        // myargs[0] = "ls";
        // myargs[1] = NULL;
        // // v types
        // execv("/bin/ls", myargs);
        // execve("/bin/ls", myargs, NULL);
        // execvp("/bin/ls", myargs);

        perror("exec");
        exit(1);
    }
    else
    {
        waitpid(pid, NULL, 0);
        // wait(NULL);
        printf("I'm the parent! my pid is %d\n", pid);
    }

    return 0;
}
