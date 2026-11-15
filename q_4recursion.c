#include <stdio.h>

/* 4a: sum of the first n numbers */
int sumNumbers(int n)
{
    if (n <= 1)
        return n;
    return n + sumNumbers(n - 1);
}

/* 4b: factorial */
long long factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

/* 4c: nth term of fibonacci (term 0 = 0, term 1 = 1) */
int fibTerm(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibTerm(n - 1) + fibTerm(n - 2);
}

/* 4d: print n terms of fibonacci */
void fibSeries(int a, int b, int n)
{
    if (n == 0)
        return;
    printf("%d ", a);
    fibSeries(b, a + b, n - 1);
}

int main()
{
    int n;

    printf("Enter n for the sum: ");
    scanf("%d", &n);
    printf("Sum of first %d numbers = %d\n", n, sumNumbers(n));

    printf("\nEnter a number for factorial (0 to 20): ");
    scanf("%d", &n);
    if (n < 0 || n > 20)
        printf("Number out of range\n");
    else
        printf("Factorial of %d = %lld\n", n, factorial(n));

    printf("\nEnter n for the nth fibonacci term: ");
    scanf("%d", &n);
    printf("Term %d = %d\n", n, fibTerm(n));

    printf("\nHow many fibonacci terms to print? ");
    scanf("%d", &n);
    fibSeries(0, 1, n);
    printf("\n");

    return 0;
}