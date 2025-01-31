#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef unsigned int WholeNum;

WholeNum get_zero() {
    return 0;
}

bool is_zero(WholeNum x) {
    return x == 0;
}

WholeNum get_sum(WholeNum x, WholeNum y) {
    if (UINT_MAX - x < y) { // UNIT_MAX - maximum value an object of type unsigned int can hold
        return UINT_MAX;
    }
    return x+y;  
}

bool is_equal(WholeNum x, WholeNum y){
    return x==y;
}

WholeNum get_successor(WholeNum x) {
    if (x == INT_MAX) {
        return INT_MAX;
    }
    return x+1; 
}

WholeNum get_difference(WholeNum x, WholeNum y) {
    if (x < y) {
        return 0;
    }
    return x - y;
}


int main() {
    WholeNum zero = get_zero();
    WholeNum one = get_successor(zero);
    WholeNum sum = get_sum(one, one);

    if (is_zero(zero)) {
        printf("0 is zero\n");
    }
    if (is_equal(one, sum)) {
        printf("Kuch to galat hai, 1 is not equal \n");
    }
    return 0;
}