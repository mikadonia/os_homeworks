#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5

char s[N];
int position = 0;
int cSleep, pSleep;
long long int t;

void *Producer(void *arg)
{
	while (1){
    	if (pSleep)
    	        continue;
    	if (position == 5){
        	cSleep = 0;
        	pSleep = 1;
        	printf("Time %lld \n", t++);
        	continue;
    	}
    	s[position] = 'a' + position;
    	position++;
    }
    pthread_exit(NULL);
    return NULL;

}

void *Consumer(void *arg)
{
	while (1)
	{
	    if (cSleep)
	        continue;
		if (position == 0)
		{
    		cSleep = 1;
    		pSleep = 0;
    		continue;
		}
		printf("%c", s[position]);
		position--;
	}
	pthread_exit(NULL);
	return NULL;
}

int main()
{
    cSleep = 1; //consumer sleep first
	pthread_t prod;
	pthread_t cons;
	
	pthread_create(&prod, NULL, Producer, NULL);
	pthread_create(&cons, NULL, Consumer, NULL);
	while(1);
	
	return 0;
}