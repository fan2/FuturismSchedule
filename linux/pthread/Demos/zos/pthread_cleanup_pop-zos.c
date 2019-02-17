/*https://www.ibm.com/support/knowledgecenter/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/ptclpop.htm*/

/* CELEBP15 */
#define _OPEN_THREADS

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int iteration;

void noise_maker(void *arg)
{
    printf("hello from noise_maker in iteration %d!\n", iteration);
}

void *thread(void *arg)
{
    pthread_cleanup_push(noise_maker, NULL);
    pthread_cleanup_pop(iteration == 1 ? 0 : 1);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thid;
    void *ret;

    for (iteration = 1; iteration <= 2; iteration++)
    {
        if (pthread_create(&thid, NULL, thread, NULL) != 0)
        {
            perror("pthread_create() error");
            exit(1);
        }

        if (pthread_join(thid, &ret) != 0)
        {
            perror("pthread_join() error");
            exit(2);
        }

        printf("pthread_join %p\n", thid);

        /*
        if (pthread_detach(&thid) != 0)
        {
            perror("pthread_detach() error");
            exit(3);
        }
        */
    }

    return EXIT_SUCCESS;
}
