#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int mem = 10 * 1024 * 1024; //10 MB

int main(){
	for (int i = 1; i <= 10; ++i) { //runs for 10 seconds
		int *x = (int*)malloc(mem); // allocate 10MB of memory
		memset(x, 0, mem); // fill it with zeros using memset(ptr,value,size)
		sleep(1); // sleep for 1 second
	}
    return 0;
}
