#include "utils.h"

#include <stdio.h>

unsigned long long fib_recursive(unsigned long long n)
{
        if (n == 1)
                return 1;
        else if (n == 0)
                return 0;
        else
                return fib_recursive(n-2) + fib_recursive(n-1);
}

unsigned long long fib_dynamic(unsigned long long n)
{
        unsigned long long fib_list[n + 1];

        for(unsigned long long i = 0; i <= n; i++) {
                if(i == 0)
                        fib_list[i] = 0;
                else if(i == 1)
                        fib_list[i] = 1;
                else
                        fib_list[i] = fib_list[i - 2] + fib_list[i - 1];
        }

        return fib_list[n];
}

int main(int argc, char** argv)
{
        unsigned long long res = fib_recursive(10);

        printf("%lld\n", res);

        res = fib_dynamic(10);
        printf("%lld\n", res);


        return 0;
}