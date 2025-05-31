#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int balance = 1000;
pthread_mutex_t mutex;

void *deposit()
{
   pthread_mutex_lock(&mutex);
   balance += 50;
   pthread_mutex_unlock(&mutex);
   return NULL;
}

void *withdraw()
{
    pthread_mutex_lock(&mutex);
    balance -= 50;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int read_balance()
{
  return balance;
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    int ini = read_balance();
    printf("initial balence : %d", ini);
    pthread_t  deposit_thread[1000];
    pthread_t  withdraw_thread[1000];
    
    pthread_create(&deposit_thread, NULL, &deposit, NULL);
    for (int i = 0; i < 1000; i++)
        deposit();
    pthread_mutex_lock(&mutex);
    if (balance >= 50)
        pthread_create(&withdraw_thread, NULL, &withdraw, NULL);
    pthread_mutex_unlock(&mutex);
    for (int x = 0; x < 1000; x++)
        withdraw();
    for (int j = 0; j < 1000; j++)
        pthread_join(&deposit_thread[j], NULL);
    for (int t = 0; t < 1000; t++)
        pthread_join(&withdraw_thread[t], NULL);

    int hh = read_balance();
    printf("balence is : %d", hh);

    pthread_mutex_destroy(&mutex);
    return 0;
}