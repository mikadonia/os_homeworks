#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int mem = 10 * 1024 * 1024; //10 MB

int main(){
	for (int i = 1; i <= 10; ++i) { //runs for 10 seconds
		int *x = (int*)malloc(mem); // allocate 10MB of memory
		memset(x, 0, mem); // fill it with zeros using memset(ptr,value,size)
        struct rusage usage;
        getrusage(RUSAGE_SELF,&usage); //int getrusage(int who, struct rusage *usage);
        printf("ru_rss: %ld\n", (usage).ru_maxrss); //print memory usage
		sleep(1); // sleep for 1 second
	}
    return 0;
}
