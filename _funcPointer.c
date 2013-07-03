#include <pthread.h>
#include <stdio.h>

void * print_G(void *argu)
{
		while (1)
		{
			printf("Print G \n");
			sleep(1);
		}
		return NULL;
}

void * print_K(void *argu)
{
		while (1)
		{
			printf("Print K \n");
			sleep(2);
		}
		return NULL;
}

int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &print_G, NULL);
	pthread_create(&thread2, NULL, &print_K, NULL);
	while (1)
	{
		printf("-------------------\n");
		sleep(1);
	}
	return 0;
}
