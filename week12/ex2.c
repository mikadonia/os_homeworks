#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
	char c;
	FILE *output;
	
	if (argc == 1) { //if number of args in command line equal to 1
		while(scanf("%c", &c) == 1) { 
			printf("%c", c);
		}
	} else if (argc == 2) { //if number of args in command line equal to 2
		output = fopen(argv[1], "w"); //argv[1] is the first string after the program name
		                              //write: Create an empty file for output operations. 
		                              //If a file with the same name already exists, 
		                              //its contents are discarded and the file is treated as a new empty file.
		while(scanf("%c", &c) == 1) {
			fprintf(output, "%c", c); //int fprintf( FILE * stream, const char * format, ... );
			printf("%c", c);
		}	
	} else if (argc == 3) { //if number of args in command line equal to 3
		output = fopen(argv[2], "a"); //argv[2] is the second string after the program name
		                              //append: Open file for output at the end of a file.
		while(scanf("%c", &c) == 1) {
			fprintf(output, "%c", c); //int fprintf( FILE * stream, const char * format, ... );
			printf("%c", c);
		}	
	}
	
	return 0;
}
