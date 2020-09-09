#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX = 10000;

int main()
{
	char c[MAX];
	fgets(c, MAX, stdin);
	system(c);
	return 0;
}