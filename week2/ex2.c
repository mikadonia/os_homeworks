#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    printf("Enter the string:");
    scanf("%s", str);

    int str_length = strlen(str) - 1;

    while (str_length >= 0){
        printf("%c", str[str_length--]);
    }
    return 0;
}

