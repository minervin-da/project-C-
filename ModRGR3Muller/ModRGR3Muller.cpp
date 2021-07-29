#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <conio.h> 
#include <ctime>
#include <math.h>

double RandomGenerator()
{
    return ((double)(rand()) + 1.) / ((double)(RAND_MAX)+1.);
}

double randomMuller()
{    
    double x1 = RandomGenerator(), x2 = RandomGenerator();
    return (cos(2 * 3.14 * x2) * sqrt(-2. * log(x1)));
}


int main()
{
    setlocale(LC_ALL, ("Russian"));
    int const N = 100000;
     double  testRandom[N];
    int const t = 21;
    double interval[t] = {-1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
    long double m = 0, D = 0;
    long double n = 0, k = 0;
    int i = 0;
    int c[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    double sigma = 0.5, Mi = 0;

    for (int i = 0; i < N; i++)
    {
        testRandom[i] = randomMuller()*sigma+Mi;   // случайное число от 0 до 1
        //std::cout << "Случайные числа: " << testRandom[i] << std::endl;
    }

    // Определяем матожидание случайных чисел
    for (int i = 0; i < N; i++)
    {
        n += testRandom[i];
      
    }
    m = n / N;

    // Определяем дисперсию случайних чисел
    for (i = 0; i < N; i++)
    {
        k += (testRandom[i] - m) * (testRandom[i] - m);
    }

    D = k / N;

    std::cout << "Матожидание m = " << m << std::endl;
    std::cout << "Дисперсия D = " << D << std::endl;


    for (int i = 0; i < N; i++)
    {
        if ((testRandom[i] >= -1) && (testRandom[i] <= -0.9))
            c[0]++;
        if ((testRandom[i] >= -0.9) && (testRandom[i] <= -0.8))
            c[1]++;
        if ((testRandom[i] >= -0.8) && (testRandom[i] <= -0.7))
            c[2]++;
        if ((testRandom[i] >= -0.7) && (testRandom[i] <= -0.6))
            c[3]++;
        if ((testRandom[i] >= -0.6) && (testRandom[i] <= -0.5))
            c[4]++;
        if ((testRandom[i] >= -0.5) && (testRandom[i] <= -0.4))
            c[5]++;
        if ((testRandom[i] >= -0.4) && (testRandom[i] <= -0.3))
            c[6]++;
        if ((testRandom[i] >= -0.3) && (testRandom[i] <= -0.2))
            c[7]++;
        if ((testRandom[i] >= -0.2) && (testRandom[i] <= -0.1))
            c[8]++;
        if ((testRandom[i] >= -0.1) && (testRandom[i] <= 0.0))
            c[9]++;
        if ((testRandom[i] >= 0.0) && (testRandom[i] <= 0.1))
            c[10]++;
        if ((testRandom[i] >= 0.1) && (testRandom[i] <= 0.2))
            c[11]++;
        if ((testRandom[i] >= 0.2) && (testRandom[i] <= 0.3))
            c[12]++;
        if ((testRandom[i] >= 0.3) && (testRandom[i] <= 0.4))
            c[13]++;
        if ((testRandom[i] >= 0.4) && (testRandom[i] <= 0.5))
            c[14]++;
        if ((testRandom[i] >= 0.5) && (testRandom[i] <= 0.6))
            c[15]++;
        if ((testRandom[i] >= 0.6) && (testRandom[i] <= 0.7))
            c[16]++;
        if ((testRandom[i] >= 0.7) && (testRandom[i] <= 0.8))
            c[17]++;
        if ((testRandom[i] >= 0.8) && (testRandom[i] <= 0.9))
            c[18]++;
        if ((testRandom[i] >= 0.9) && (testRandom[i] <= 1.0))
            c[19]++;
    }
   
    for (i = 0; i < 20; i++)
    {
        std::cout << "Количество чисел на интервале от " << interval[i] << " до " << interval[i + 1] << " с = " << c[i] << std::endl;
    }

    _getch();
    return 0;
}