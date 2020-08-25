#include <stdio.h>
#include <string.h>

void swap (int* a, int* b){
    int swap = *a;
    *a = *b;
    *b = swap;
}


int main(){
    int a;
    int b;
    printf("Enter two integers:");
    scanf("%d", &a);
    scanf("%d", &b);

    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}