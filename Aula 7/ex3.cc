#include <iostream>

using namespace std;

class Termometro {
private:
    double temperaturaCelsius;

public:
    Termometro() {
        temperaturaCelsius = 25.0;
    }

    void setTemperaturaCelsius(double temperaturaCelsius) {
        if (temperaturaCelsius >= -273.15) {
            this->temperaturaCelsius = temperaturaCelsius;
        }
    }

    double getTemperaturaCelsius() {
        return temperaturaCelsius;
    }

    double getTemperaturaFahrenheit() {
        return (temperaturaCelsius * 9.0 / 5.0) + 32;
    }
};

int main() {
    Termometro termometro;

    termometro.setTemperaturaCelsius(30.0);

    cout << "Temperatura em Celsius: "
         << termometro.getTemperaturaCelsius() << endl;

    cout << "Temperatura em Fahrenheit: "
         << termometro.getTemperaturaFahrenheit() << endl;

    return 0;
}