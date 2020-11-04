#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	int input;
    input = open("/dev/urandom", O_RDONLY);
  	unsigned char s[21]; 	// 20 symbols + 1 char of the end of the string '\0'

	read(input, s, 20);
  	s[20] = '\0';

  	//make string readable for us by using ASCII table and print
  	for(size_t i = 0; i < 21; ++i){
        putchar(32 + s[i] % 60);
    }
  	
	close(input);
	
	return 0;
}
