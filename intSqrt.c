#include <stdio.h>

int sq(int n) {
    int i;
    for (i = 0; (i*i) <= n; i++) {
        if (i*i == n) {
            return i;
        }  
    }
    return i-1;
}

int main() {
    printf("%d", sq(50));
    return 0;
}