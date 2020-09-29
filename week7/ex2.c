#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int N;
    printf("Enter N: \n");
	scanf("%d", &N);
    
    //allocate memory
	int *arr = (int*)malloc(N*sizeof(int));
    
    //fill the array
	arr[0] = 0;
	for (int i = 1; i < N; ++i)
		arr[i] = i;
        
    //prints the array
	for (int i = 0; i < N; ++i)
		printf("%d ", arr[i]);
    
    //deallocate memory
	free(arr);
    
	return 0;
}
