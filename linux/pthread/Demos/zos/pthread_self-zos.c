/* CELEBP47 */
#define _OPEN_THREADS

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_t thid, IPT;

void *thread(void *arg)
{
    if (pthread_equal(IPT, pthread_self()))
        puts("the thread is the IPT...?");
    else
        puts("the thread is not the IPT");

    if (pthread_equal(thid, pthread_self()))
        puts("the thread is the one created by the IPT");
    else
        puts("the thread is not the one created by the IPT...?");

    return NULL;
}

int main(int argc, char *argv[])
{
    IPT = pthread_self();
    if (pthread_create(&thid, NULL, thread, NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    if (pthread_join(thid, NULL) != 0)
    {
        perror("pthread_create() error");
        exit(3);
    }

    return EXIT_SUCCESS;
}