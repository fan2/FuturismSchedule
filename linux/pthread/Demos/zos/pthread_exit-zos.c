/*https://www.ibm.com/support/knowledgecenter/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/ptexit.htm*/

/* CELEBP30 */
#define _OPEN_THREADS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *thread(void *arg)
{
    char *ret;

    if ((ret = (char *)malloc(20)) == NULL)
    {
        perror("malloc() error");
        exit(2);
    }
    strcpy(ret, "This is a test");
    pthread_exit(ret);
}

int main(int argc, char *argv[])
{
    pthread_t thid;
    void *ret;

    if (pthread_create(&thid, NULL, thread, NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    if (pthread_join(thid, &ret) != 0)
    {
        perror("pthread_create() error");
        exit(3);
    }

    printf("thread exited with '%s'\n", ret);
    free(ret);

    return EXIT_SUCCESS;
}