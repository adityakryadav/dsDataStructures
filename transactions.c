#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char transaction_date[11]; // "YYYY-MM-DD", but why? because year is super category then comes other so here dictionary order is enforced
    float amount;
} Transaction;

Transaction *global_transactions = NULL;
// variabl to hold transactions for comparison

// Indirectly structure definintion
typedef struct
{
    int *indices;
    int size;
} IndirectArray;

// Function prototypes
IndirectArray *create_indirect_array(int size);

int sort_transactions(
    IndirectArray *indirect_array,
    Transaction *transactions,
    int size,
    char *sort_param);

Transaction *get_transaction(IndirectArray *indirect_array, Transaction *transactions, int index);

int destroy_indirect_array(IndirectArray *indirect_array);

// Implementation
IndirectArray *create_indirect_array(int size)
{
    IndirectArray *indirect_array = (IndirectArray *)malloc(sizeof(IndirectArray));
    indirect_array->indices = (int *)malloc(size * sizeof(int));
    indirect_array->size = size;

    for (int i = 0; i < size; ++i)
    {
        indirect_array->indices[i] = i;
    }
    return indirect_array;
}
// Comparators

int compare_by_date(const void *a, const void *b)
{
    int index_a = *(const int *)a;
    int index_b = *(const int *)b;
    return strcmp(global_transactions[index_a].transaction_date,
                  global_transactions[index_b].transaction_date);
}
int compare_by_amount(const void *a, const void *b)
{
    int index_a = *(const int *)a;
    int index_b = *(const int *)b;

    if (global_transactions[index_a].amount < global_transactions[index_b].amount)
    {
        return -1;
    }
    if (global_transactions[index_a].amount < global_transactions[index_b].amount)
    {
        return 1;
    }
}
    int sort_transactions(IndirectArray * indirect_array, Transaction * transactions, int size, char *sort_param)
    {
        // set the global transactions
        global_transactions = transactions;
        if (strcmp(sort_param, "date") == 0)
        {
            qsort(indirect_array->indices, size, sizeof(int), compare_by_date);
        }
        else if (strcmp(sort_param, "amount") == 0)
        {
            qsort(indirect_array->indices, size, sizeof(int), compare_by_amount);
        }
        // Reset the global variable to prevetn unintended side effects
        global_transactions = NULL;

        return 0;
    }