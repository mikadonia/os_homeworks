#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
  
void *threadFunc(void *arg) 
{ 
	printf("thread id %d \n", (*(int *)arg)); 
	return; 
} 
   
int N = 5;

int main() 
{ 
  	pthread_t some_thread[N]; 
	for (int i = 1; i <= N; ++i) {
		printf("thread created\n");
		pthread_create(&some_thread[i], NULL, threadFunc, (void *)(&some_thread[i])); 
	}	
	for (int i = 1; i <= N; ++i) {
		pthread_join(some_thread[i], NULL); 
	}	
	return 0;
}