/*https://www.ibm.com/support/knowledgecenter/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/ptyield.htm*/

/* CELEBP53 */
#define _OPEN_THREADS

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread(void *arg)
{

    /* A simple loop with only puts() would allow a thread to write several
    lines in a row.
    With pthread_yield(), each thread gives another thread a chance before
    it writes its next line */

    while (1)
    {
        puts((char *)arg);
        // pthread_yield(NULL);
        pthread_yield_np();
    }
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2, t3;

    if (pthread_create(&t1, NULL, thread, "thread 1") != 0)
    {
        perror("pthread_create(1) error");
        exit(1);
    }

    if (pthread_create(&t2, NULL, thread, "thread 2") != 0)
    {
        perror("pthread_create(2) error");
        exit(2);
    }

    if (pthread_create(&t3, NULL, thread, "thread 3") != 0)
    {
        perror("pthread_create(3) error");
        exit(3);
    }

    sleep(1);

    // exit(0); /* this will tear all threads down */
    return EXIT_SUCCESS;
}