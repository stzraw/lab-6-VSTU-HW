#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int task1();
int task2();
int HW();

int visyear(int year);
double resf(double x);
int cifra(int n, int zapros);

int main()
{
    setlocale(LC_ALL, ".UTF8");
    task1();
    task2();
    HW();
    return 0;
}

int task1()
{
    int year, res;

    printf("Задание 1:\n");
    printf("Введите год: ");
    scanf("%d", &year);

    res = visyear(year);
    if (res == 1)
    {
        printf("год %d високосный\n", year);
    }
    else
    {
        printf("год %d не високосный\n", year);
    }
    return 0;
}

int task2()
{
    double x, F;

    printf("\nЗадание 2:\n");
    printf("Введите x: ");
    scanf("%lf", &x);
    F = resf(x);

    printf("F(%.2lf) = %.4lf (%s)\n", x, F, (x <= -3.0) ? "x <= -3" : "x > -3");
    return 0;
}

int HW()
{
    int n, zapros, result;

    printf("\nДомашнее задание:\n");
    printf("Введите число N (N < 1000): ");
    scanf("%d", &n);
    printf("Что вывести? (1 - первую цифру, 2 - последнюю цифру): ");
    scanf("%d", &zapros);
    result = cifra(n, zapros);

    if (result == -1)
    {
        printf("Ошибка: введены некорректные данные\n");
    }
    else
    {
        printf("Искомая цифра: %d\n", result);
    }
    return 0;
}

int visyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double resf(double x)
{
    // если x = -4, то F(-4) = 9
    // если x = 2, то F(2) = 1 / (2^2 + 1) = 0.2000
    double F;

    if (x <= -3.0)
    {
        F = 9.0;
    }
    else
    {
        F = 1.0 / (pow(x, 2) + 1.0);
    }
    return F;
}

int cifra(int n, int zapros)
{
    int m, ans;
    m = abs(n);

    if (m >= 1000 || (zapros != 1 && zapros != 2))
    {
        return -1;
    }

    if (zapros == 1)
    {
        if (m >= 100)
        {
            ans = m / 100;
        }
        else if (m >= 10)
        {
            ans = m / 10;
        }
        else
        {
            ans = m;
        }
    }
    else
    {
        ans = m % 10;
    }
    return ans;
}