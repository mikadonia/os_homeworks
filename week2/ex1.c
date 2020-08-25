#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("size = %lu, value = %d \n", sizeof(a), a);
    printf("size = %lu, value = %f \n", sizeof(b), b);
    printf("size = %lu, value = %lf", sizeof(c), c);

    return 0;
}
