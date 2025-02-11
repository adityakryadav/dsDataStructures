#include <stdio.h>

int root(int n) {
    int bgn=0, mid;
    int end=n-1;
    while (bgn<=end) {
        mid=(bgn+end)/2;
        if ( mid*mid == n ) {
            return mid;
        }
        else if (mid*mid >= n) {
            end = mid-1;
        }
        else {
            bgn = mid+1;
        }       
    }
}

int main() {
    printf("%d", root(36));
    return 0;
}