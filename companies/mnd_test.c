/** @file test.c
 *
 * A small example of daemon code.  It forks off
 * a child process, while the parent exits immediately.
 *
 * @todo Close file descriptors in the child.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


/** Parameters to be passed to the daemon. */
struct params {
   pid_t pid;
   unsigned sleeptime;
};

/** Functionality of the child process.
 *
 * This is the main function of the daemon.  Fill in the
 * daemon functionality in this function.
 *
 * Any parameters that have to be passed to the daemon
 * are collected in the params struct.
 */
void childfunc (struct params *params)
{
    sleep(params->sleeptime);
    printf("Child has stopped.\n");
}

int main (int argc, char* argv[])
{
    struct params params;

    printf("Parent started: ");
    fflush(stdout);
    params.sleeptime = 3;
    if ( (params.pid = fork()) < 0) {
        printf("fork failed: %m!\n");
        return 1;
    } else if (params.pid > 0) {
        printf("child forked with PID %d and will sleep for %u seconds.\n", params.pid, params.sleeptime);
    } else {
        childfunc(&params);
    }

    return 0;
}
