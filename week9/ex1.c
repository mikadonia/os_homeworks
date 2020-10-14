#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int id;
    unsigned int counter;
} page;

unsigned int RBit = 1u << (sizeof(int) * 8 - 1);
int numPage = 0; //number of pages
int hit = 0; //number of hits
int miss = 0; //number of misses
FILE *inputFile = NULL;

// Check the table
char check(int pageId, page table[]) {
    for (int i = 0; i < numPage; ++i) {
        if (table[i].id == pageId) {
            return 1; //hit
        }
    }
    return 0;//miss
}

void insert(int pageId, page table[]) {
    unsigned int minIndex = -1;
    unsigned int minCounter = -1;
    for (int i = 0; i < numPage; ++i) {
        if (table[i].id == -1) {
            table[i].id = pageId;
            return;
        }
        if (table[i].counter < minCounter) {
            minIndex = i;
            minCounter = table[i].counter;
        }
    }

    assert(minIndex != -1); //check error
    table[minIndex].id = pageId;
}

void update(int pageId, page table[]) {
    for (int i = 0; i < numPage; ++i) {
        table[i].counter >>= 1u;
        if (table[i].id == pageId) {
            table[i].counter |= RBit;
        }
    }
}


// Return next referencing page number from the input file
int next_page() {
    int temp = 0;
    if (fscanf(inputFile, "%d", &temp) == 1) {
        return temp;
    }
    return -1;
}

// Initialize page table with zeros
void initialize(page table[]) {
    for (int i = 0; i < numPage; ++i) {
        table[i].id = -1;
        table[i].counter = 0;
    }
}


int main(int argc, char *argv[]) {

    if (argc != 3) {
        exit(0);
    }

    numPage = (int) strtol(argv[1], NULL, 10); //long strtol(const char *start, char **end, int radix)

    if (numPage < 1) {
        printf("incorrect");
        exit(0);
    }

    inputFile = fopen(argv[2], "r");
    if (inputFile == NULL) {
        printf("no data");
        exit(0);
    }

    page table[numPage];
    initialize(table);

    // Index of the referencing page
    int ref_index = -1;

    while ((ref_index = next_page()) != -1) {

        if (check(ref_index, table)) {
            hit++;
        } 
        else {
            miss++;
            insert(ref_index, table);
        }
        update(ref_index, table);
    }

    printf("Hit/Miss ratio: %lf\n", (double) hit / miss);

    return 0;
}

