#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum { INT, DOUBLE,  STRING } DataType;

typedef struct {
    void *data;
    DataType type;
} ListItem;

typedef struct {
    ListItem *items;
    size_t size;
    size_t capacity;
} PyList;

// Function to initialize the list
void create_list(PyList *list, size_t capacity) {
    list->items = malloc(capacity * sizeof(ListItem));
    list->size = 0;
    list->capacity = capacity;
}

// Function to resize the list when full
void resize_list(PyList *list) {
    list->capacity *= 2;
    list->items = realloc(list->items, list->capacity * sizeof(ListItem));
}

// Function to append an integer
void append_int(PyList *list, int value) {
    if (list->size == list->capacity)
        resize_list(list);
    
    list->items[list->size].data = malloc(sizeof(int));
    *(int *)list->items[list->size].data = value;
    list->items[list->size].type = INT;
    list->size++;
}

// Function to append a double
void append_double(PyList *list, double value) {
    if (list->size == list->capacity)
        resize_list(list);
    
    list->items[list->size].data = malloc(sizeof(double));
    *(double *)list->items[list->size].data = value;
    list->items[list->size].type = DOUBLE;
    list->size++;
}

// Function to append a string
void append_string(PyList *list, const char *value) {
    if (list->size == list->capacity)
        resize_list(list);
    
    list->items[list->size].data = malloc(strlen(value) + 1);
    strcpy((char *)list->items[list->size].data, value);
    list->items[list->size].type = STRING;
    list->size++;
}

void extend(PyList *list1, PyList *list2) {

}

void insert(PyList *list, int index, ListItem val) {

}

void remove(PyList *list, ListItem val) {

}

void pop(PyList *list, int index) {
    
}

void clear(PyList *list) {

}

void index() {

}

int count(PyList *list, ListItem val) {

}

void sort(PyList *list, bool order) {

}

void reverse(PyList *list) {

}

PyList* copy(PyList *list) {
    
}

// Function to get an item from the list
void *get_item(PyList *list, size_t index, DataType *type) {
    if (index >= list->size)
        return NULL;
    
    *type = list->items[index].type;
    return list->items[index].data;
}

// Function to free allocated memory
void free_list(PyList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->items[i].data);
    }
    free(list->items);
}

int main() {
    PyList list;
    create_list(&list, 5);

    append_int(&list, 42);
    append_double(&list, 3.14);
    append_string(&list, "Hello, world!");

    for (size_t i = 0; i < list.size; i++) {
        DataType type = list.items[i].type;
        if (type == INT)
            printf("Item %lu (int): %d\n", i, *(int *)list.items[i].data);
        else if (type == DOUBLE)
            printf("Item %lu (double): %.2f\n", i, *(double *)list.items[i].data);
        else if (type == STRING)
            printf("Item %lu (string): %s\n", i, (char *)list.items[i].data);
    }

    free_list(&list);
    return 0;
}
