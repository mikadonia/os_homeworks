#include <stdio.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

typedef struct list list;

void print_list(list head){
    list *first = head.next;
    while (first != NULL){
        printf("%d ", first -> value);
        first = first -> next;
    }
    printf("\n");
}

void insert_node(list *after, int new_value){
    list *cell = (list*)malloc(sizeof(list));
    cell -> value = new_value;
    cell -> next = after -> next;
    after -> next = cell;
}

void delete_node(list *head, int node){
    list *first = head;
    while (first -> next != NULL && first -> next -> value != node)
        first = first -> next;

    list *temp = first -> next;
    first -> next = (first -> next) -> next;
    free(temp);
}

int main(){
    list myList;            
    myList.next = NULL;      
    return 0;
}
