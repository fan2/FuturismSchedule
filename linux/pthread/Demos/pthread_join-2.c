/*https://github.com/tomohikoseven/pthread_join/blob/master/main.c*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int test()
{
    return 2; // 等效于 pthread_exit((void*)2);
}

int main(int argc, char *argv[])
{
    pthread_t thread_id;
    pthread_attr_t *pthread_attr = NULL; // default attributes, modified later will not affected
    void *(*start_routine)(void *) = test;
    void *arg = NULL;

    int ret;
    void *thread_return;

    ret = pthread_create(&thread_id, pthread_attr, start_routine, arg);
    if (0 != ret) // EAGAIN or EINVAL
    {
        printf("pthread_create error.\n");
        exit(1); // implicit call to exit from main thread
    }

    ret = pthread_join(thread_id, &thread_return);
    if (0 != ret)
    {
        printf("pthread_join error.\n");
        exit(1); // implicit call to exit from main thread
    }

    printf("thread_return:%p\n", thread_return);

    return EXIT_SUCCESS;
}
