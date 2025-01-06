#include <stdio.h>

int fib(int n) {
    if (n < 2) {
        return 1;
    }
    return fib(n-2) + fib(n-1);
}

int main(void) {
    int n=3, f;

    while (n > 0) {
        printf("\nDigite um número: ");
        scanf("%d", &n);
        f = fib(n);
        printf("\nfib(%d)=%d", f);
    }

    return 0;
}