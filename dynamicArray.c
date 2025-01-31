#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {

    int* ptr = (int*) malloc(size*sizeof(int));

    for (int i = 0; i < size; ++i) {
        scanf("%d", ptr+i);
    }

    return ptr;
}

void append(int* arr, int oldSize) {

    arr = (int*) realloc(arr, (oldSize + 1)*(sizeof(int)));

    scanf("%d", arr+oldSize);
    return;
}

void extend(int* arr, int* brr, int size) {
    
    return;
}

void print(int* arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(arr+i));
    }
    printf("]");
    return;
}





int main() {
    int* list = createArray(3);
    // print(list, 3);
    // append(list, 3);
    print(list, 7);
    return 0;
}