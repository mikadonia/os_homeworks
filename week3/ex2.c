#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
void bubble_sort(int *a)
{
    for (int i = 0; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (*(a + j - 1) > *(a + j)){
                int temp = *(a + j - 1);
                *(a + j - 1) = *(a + j);
                *(a + j) = temp;
            }
}

int main()
{

    int a[N] = {5, 4, 8, 6, 3, 7, 9, 2, 1, 11};       
    for (int i = 0; i < N; ++i){
        printf("%d ", a[i]);
    };
    printf("\n");
    bubble_sort(a);
    for (int i = 0; i < N; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}
