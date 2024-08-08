#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int count = 0;
pthread_mutex_t mutex;

void write_balance(int amount)
{
	usleep(25000);
	count = amount;
}
int get_balance()
{
	usleep(25000);
	return (count);
}

void *deposit(void *amount)
{
	pthread_mutex_lock(&mutex);
	int balance = get_balance();
	balance += *((int*)amount);
	write_balance(balance);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int main(int arc, char *argv)
{
	pthread_t thread1;
	pthread_t thread2;

	int dep1 = 200;
	int dep2 = 300;

	pthread_mutex_init(&mutex,NULL);

	printf("saldo cuenta:%d\n",count);
	pthread_create(&thread1,NULL,deposit,(void *)&dep1);
	pthread_create(&thread1,NULL,deposit,(void *)&dep2);

	pthread_join(thread1,NULL);
	pthread_join(thread1,NULL);

	pthread_mutex_destroy(&mutex);

	printf("saldo cuenta:%d\n",get_balance());
}