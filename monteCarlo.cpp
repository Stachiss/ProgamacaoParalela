#include <iostream>
#include <iomanip>
#include <random>
#include <omp.h>

using namespace std;
int main() {
    const long long int num_points = 10000; // Número total de pontos
    long long int num_points_inside_circle = 0; // Número de pontos dentro do círculo
    double x, y, distance_squared;

    random_device rd; // Gerador de números aleatórios
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    #pragma omp parallel for reduction(+:num_points_inside_circle)
    for (long long int i = 0; i < num_points; ++i) {
        x = dis(gen);
        y = dis(gen);
        distance_squared = x * x + y * y;

        if (distance_squared <= 1.0) {
            num_points_inside_circle++;
        }
    }

    double pi = 4.0 * num_points_inside_circle / num_points;

    cout << fixed << setprecision(7);
    cout << "Estimativa de Pi: " << pi << endl;

    return 0;
}
