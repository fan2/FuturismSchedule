/*https://www.ibm.com/support/knowledgecenter/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/ptcpush.htm*/

/* CELEBP16 */
#define _OPEN_THREADS

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int footprint = 0;

void *thread(void *arg)
{
    char *storage;

    if ((storage = (char *)malloc(80)) == NULL)
    {
        perror("malloc() failed");
        exit(6);
    }

    /* Plan to release storage even if thread doesn't exit normally */

    pthread_cleanup_push(free, storage);

    puts("thread has obtained storage and is waiting to be cancelled");
    footprint++;
    while (1)
        sleep(1);

    pthread_cleanup_pop(1);
}

int main(int argc, char *argv[])
{
    pthread_t thid;
    void *res;

    if (pthread_create(&thid, NULL, thread, NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    /* Allow new thread to run a while */
    while (footprint == 0)
        sleep(1);

    puts("IPT is cancelling thread");

    if (pthread_cancel(thid) != 0)
    {
        perror("pthread_cancel() error");
        exit(3);
    }

    if (pthread_join(thid, &res) != 0)
    {
        perror("pthread_join() error");
        exit(4);
    }

    if (res == PTHREAD_CANCELED)
        puts("Thread was canceled");
    else
        puts("Thread terminated normally");

    return EXIT_SUCCESS;
}
