#include <iostream>
#include <cmath>
#include <omp.h>

double calculate_pi(int n)
{
    int count = 0;
    double h = 1.0 / n;
    double sum = 0.0;

#pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; ++i)
    {
        double x = h * (i - 0.5);
        sum += 4.0 / (1.0 + x * x);
    }

    return h * sum;
}

int main()
{
    int n = 10000;
    double pi = calculate_pi(n);

    std::cout << "Valor de pi: " << pi << std::endl;

    return 0;
}
