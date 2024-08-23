//GARCÍA ESCOBAR ANGÉLICA YAZMÍN
//SIMULACIÓN I
#include <iostream>
#include <random>
#include <queue>

// Generador de números aleatorios con distribución exponencial
class ExponentialDistribution {
public:
    ExponentialDistribution(double rate) : generator(std::random_device()()), distribution(rate) {}

    double operator()() {
        return distribution(generator);
    }

private:
    std::mt19937 generator;
    std::exponential_distribution<double> distribution;
};

int main() {
    double arrival_rate, service_rate;
    int num_clients;
    std::queue<double> arrival_times;

    std::cout << "Ingrese la tasa media de llegada (lambda): ";
    std::cin >> arrival_rate;
    std::cout << "Ingrese la tasa media de servicio (mu): ";
    std::cin >> service_rate;
    std::cout << "Ingrese el número de clientes a simular: ";
    std::cin >> num_clients;

    // Generadores de números aleatorios con distribución exponencial
    ExponentialDistribution arrival_gen(arrival_rate);
    ExponentialDistribution service_gen(service_rate);

    double current_time = 0.0;
    double total_wait_time = 0.0;
    int num_served = 0;

    while (num_served < num_clients) {
        double next_arrival_time = current_time + arrival_gen();
        double next_service_time;

        if (arrival_times.empty() || next_arrival_time < arrival_times.back()) {
            next_service_time = next_arrival_time + service_gen();
            arrival_times.push(next_arrival_time);
        } else {
            next_service_time = arrival_times.back() + service_gen();
        }

        if (next_arrival_time < next_service_time) {
            current_time = next_arrival_time;
        } else {
            double wait_time = next_service_time - arrival_times.front();
            arrival_times.pop();
            total_wait_time += wait_time;
            num_served++;
            current_time = next_service_time;
        }
    }

    double average_wait_time = total_wait_time / num_clients;
    std::cout << "Tiempo promedio de espera: " << average_wait_time << " unidades de tiempo.\n";

    return 0;
}
