/*https://www.ibm.com/support/knowledgecenter/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/ptcanc.htm*/

/* CELEBP14 */
#define _OPEN_THREADS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

int thstatus;

void *thread(void *arg)
{
    puts("thread has started. now sleeping");
    while (1)
        sleep(1);
}

int main(int argc, char *argv[])
{
    pthread_t thid;
    void *status;

    if (pthread_create(&thid, NULL, thread, NULL) != 0)
    {
        perror("pthread_create failed");
        exit(2);
    }

    if (pthread_cancel(thid) == -1)
    {
        perror("pthread_cancel failed");
        exit(3);
    }

    if (pthread_join(thid, &status) == -1)
    {
        perror("pthread_join failed");
        exit(4);
    }

    // if (status == (int *)-1)
    if (status == (int*)PTHREAD_CANCELED)
        puts("thread was cancelled");
    else
        puts("thread was not cancelled");

    // exit(0);
    return EXIT_SUCCESS;
}