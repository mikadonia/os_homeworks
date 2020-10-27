#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(){
	int input = open("ex1.txt", O_RDONLY);
	int output = open("ex1.memcpy.txt", O_RDWR | O_CREAT, S_IRUSR + S_IWUSR + S_IRGRP + S_IWGRP + S_IROTH); //permissions
	if (input == -1){
		printf("Cannot open file I\n");
		return 0;	
	}
	if (output == -1){
		printf("Cannot open file O\n");
		return 0;	
	}

	struct stat st;

	void *i = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, input, 0);
	void *o = mmap(NULL, st.st_size, PROT_WRITE, MAP_SHARED, output, 0);

	ftruncate(output, st.st_size);

	memcpy(o, i, st.st_size); //void *memcpy(void *dest, const void *src, size_t n)
	msync(o, st.st_size, MS_SYNC);

	munmap(i, st.st_size);
	munmap(o, st.st_size);

	close(input);
	close(output);
	
	return 0;
}