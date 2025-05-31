# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

#define NUM_OF_THREADS 2
int num = 0;
pthread_mutex_t mutex;

void *routine(void *arg){
    int *p = (int *) arg;
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
        printf("thread: %d: %d\n", *p, num);
        num++;
        pthread_mutex_unlock(&mutex);
    }
    printf("test thread\n");
    printf("end\n");
    return NULL;
}



int main(int ac, char **av)
{
    pthread_t t[NUM_OF_THREADS];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_OF_THREADS; i++)
    {
        int *p = malloc(sizeof(int));
        *p = i;
        pthread_create(&t[i], NULL, &routine, p);
    }
    for (int i = 0; i < NUM_OF_THREADS; i++)
        pthread_join(t[i], NULL);
    printf("%d\n", num);
}
