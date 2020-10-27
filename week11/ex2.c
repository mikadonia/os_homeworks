#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){
	char buf[1024];
	memset(buf, '\0', sizeof(buf));
	setvbuf(stdout, buf, _IOLBF, 1024);

	fprintf(stdout,"H");
	sleep(1);
	fprintf(stdout,"e");
	sleep(1);
	fprintf(stdout,"l");
	sleep(1);
	fprintf(stdout,"l");
	sleep(1);
	fprintf(stdout,"o");
	sleep(1);
    return 0;
}