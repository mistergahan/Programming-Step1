#include <iostream>
using namespace std;

typedef long double (*P) (long double);

long double fx (long double a)
{
    return a;
}
long double farctg (long double a)
{
    return atan(a);
}
long double fsin (long double a)
{
    return sin(a);
}
long double fx4 (long double a)
{
    long double b = a*a;
    return b*b;
}

long double SUM(P func, long double &a, long double &b, int &n, long double &E)
{
    long double sum = 0.0;
    long double d = (abs(b - a)) / n;
    
    for (int i = 0; i < n; i++)
        sum += func(a + i*d);
    
    return d*sum;
}

void SRAVN (P fun, long double &a, long double &b, int &n, long double &e, unsigned long &k)
{
    int n1 = 2 * n;
    while (abs(SUM(fun, a, b, n, e) - (SUM(fun, a, b, n1, e))) >= e)
    {
        n *= 2;
        n1 = 2 * n;
        k++;
    }
    n = n1;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    // Количество отрезков
    int n = 10;
    // [a, b] - отрезок, на котором интегрируем
    // Е - точность вычислений
    long double
    a = 0,
    b = 11,
    E[4] = { 0.1, 0.01, 0.001, 0.0001 };
    
    // Массив указателей на функции
    long double(*F[4])(long double) = { fx, farctg, fsin, fx4 };
    unsigned long k = 0;
    
    cout << "Промежуток: [" << a << "; " << b << "]\n\n";
    
    //i - функции, j - точность
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
            case 0: cout << "y = x\n\n"; break;
            case 1: cout << "y = arctg(x)\n\n"; break;
            case 2: cout << "y = sin(x)\n\n"; break;
            case 3: cout << "y = x^4\n\n"; break;
        }
        
        for (int j = 0; j < 4; j++)
        {
            SRAVN(F[i], a, b, n, E[j], k);
            cout << SUM(F[i], a, b, n, E[j]) << endl;
            cout << "Шагов: " << k << endl << "Отрезков: " << n << endl;
            n = 10;
            k = 0;
        }
        cout << "-----------------\n";
    }
    
    system("pause");
    return 0;
}
