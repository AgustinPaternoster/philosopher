#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g = 0;

void * test_thread(void * arg)
{
    int pid = getpid();
    static int s = 0;

    g++;
    s++;

    printf("pid: %d , static: %d global: %d\n", pid,++s,++g);
}
int main(int arc, char **argv)
{
    int n = atoi(argv[1]);
    pthread_t thread[n];
    int i = 0;

    while (i < n)
    {
        pthread_create(&thread[i], NULL, test_thread,NULL);
        i++;
        printf("thread id:%ld\n",thread); 
    }
    pthread_exit(NULL);
    return 0;
}