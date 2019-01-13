/*https://www.ibm.com/support/knowledgecenter/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/ptkill.htm*/

/* CELEBP35 */
#define _OPEN_THREADS

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

void *threadfunc(void *parm)
{
    int threadnum;
    int *tnum;
    sigset_t set;

    tnum = parm;
    threadnum = *tnum;

    int sig;
    printf("Thread %d executing\n", threadnum);

    sigemptyset(&set);
    if (sigaddset(&set, SIGUSR1) == -1)
    {
        perror("Sigaddset error");
        pthread_exit((void *)1);
    }

    // if (sigwait(&set) != SIGUSR1)
    if (sigwait(&set, &sig) || sig != SIGUSR1)
    {
        perror("Sigwait error");
        pthread_exit((void *)2);
    }

    pthread_exit((void *)0);
}

int main(int argc, char *argv[])
{
    int status;
    int threadparm = 1;
    pthread_t threadid;
    int thread_stat;

    status = pthread_create(&threadid,
                            NULL,
                            threadfunc,
                            (void *)&threadparm);
    if (status < 0)
    {
        perror("pthread_create failed");
        exit(1);
    }

    sleep(5);

    status = pthread_kill(threadid, SIGUSR1);
    if (status < 0)
        perror("pthread_kill failed");

    status = pthread_join(threadid, (void *)&thread_stat);
    if (status < 0)
        perror("pthread_join failed");

    // exit(0);
    return EXIT_SUCCESS;
}