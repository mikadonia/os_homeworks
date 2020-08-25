#include <stdio.h>
#include <string.h>

int main(){
    int height; 
    scanf("%d", &height);

    char space = ' ';
    char star = '*';

    for (int k = 0; k < height; ++k) {

        for (int i = 0; i < height - k - 1; ++i) {
            printf("%c", space);
        }

        for (int i = 0; i < k*2 + 1; ++i) {
            printf("%c", star);
        }

        for (int i = 0; i < height - k - 1; ++i) {
            printf("%c", space);
        }

        printf("\n");

    }
    return 0;
}