#include <gmp.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    // first we get input for the number of fib and then input if we want to show all or just last
    int nthFib = 0;
    char allFib[4] = "n";

    printf("Enter the nth number of fibonacci: ");
    scanf("%d", &nthFib);

    printf("Do you want to show all number up to n or just n (y/N): ");
    scanf("%3s", allFib);

    // fib goes previous plus current equals new so a + b = c and b + c = d and so on
    // I remeber when i do this i only need 2 variables a,b because i can assign the result of a + b to a and so then then swap a and b then go again
    // fib 1, 2, 3, 5, 8, 13

    // Using gmp for larger numbers then needed
    mpz_t a, b, temp;
    mpz_init_set_ui(a, 1);
    mpz_init_set_ui(b, 2);
    mpz_init(temp);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // i can be 2 because we already have the first two values of fib
    if (strcmp(allFib, "y") == 0) {
        gmp_printf("1\n2\n");  // show first two

        for (int i = 3; i < nthFib; i++) {
            mpz_add(temp, a, b);
            mpz_set(a, b);
            mpz_set(b, temp);
            gmp_printf("%Zd\n", b);
            printf("\n");
        }
    } else {
        for (int i = 3; i < nthFib; i++) {
            mpz_add(temp, a, b);
            mpz_set(a, b);
            mpz_set(b, temp);
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Fibonacci number %d is:\n", nthFib);
    gmp_printf("%Zd\n", b);  // base 10
    printf("\n");

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(temp);

    double elapsed = (end.tv_sec - start.tv_sec) +
                     (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Elapsed time: %f seconds\n", elapsed);

    return 0;
}