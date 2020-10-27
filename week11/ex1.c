#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int ex1 = open("ex1.txt", O_RDWR); // open file ex1.txt in O_RDWR mode
	if (ex1 == -1){
		printf("Can not open the file\n");
		return 0;	
	}
    
    void* a = mmap(0, sizeof("This is a nice day"), PROT_WRITE, MAP_SHARED, ex1, 0); //void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset); 
	                                                               //PROT_WRITE Pages may be written.
	ftruncate(ex1, sizeof("This is a nisa day") - 1); //int ftruncate(int fildes, off_t length);
	memcpy(a, "This is a nice day", sizeof("This is a nice day")); //void *memcpy(void *dest, const void *source, size_t count)
	msync(a, sizeof("This is a nice day"), MS_SYNC); //int msync(void *start, size_t length, int flags);
	munmap(a, sizeof("This is a nice day")); //int munmap(void *addr, size_t length);
	
	close(ex1);
	return 0;
}