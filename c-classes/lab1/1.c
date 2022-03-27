#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int num;
    bool isPrime;
    isPrime = true;

    printf("Wprowadz liczbe: ");
    scanf("%d", &num);

    if (num < 2)
    {
        isPrime = false;
    }
    else
    {
        for (int i = 2; i < num / 2; i++)
        {
            if (num % i == 0)
            {
                isPrime = false;
            }
        }
    };

    if (isPrime)
    {
        printf("Liczba jest pierwsza");
    }
    else
    {
        printf("Liczba nie jest pierwsza");
    };

    printf("\n");

    int testNum;
    testNum = num;

    int count = 0;

    do
    {
        testNum /= 10;
        count++;
    } while (testNum != 0);

    testNum = num;
    int sum = 0;

    do
    {
        int digit = testNum % 10;
        int poww = 1;

        for (int i = 0; i < count; i++)
        {
            poww = poww * digit;
        }

        sum = sum + poww;

        testNum /= 10;

    } while (testNum != 0);

    if (sum == num)
    {
        printf("Liczba jest liczba armstronga");
    }
    else
    {
        printf("Liczba nie jest liczba armstronga");
    };

    printf("\n");
    return 0;
}