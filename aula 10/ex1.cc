#include <iostream>
#include <string>

using namespace std;

class Veiculo {
public:
    string marca;
};

class Carro : public Veiculo {
public:
    int numeroPortas;
};

int main() {
    Carro carro;

    carro.marca = "Toyota";
    carro.numeroPortas = 4;

    cout << "Marca: " << carro.marca << endl;
    cout << "Numero de portas: " << carro.numeroPortas << endl;

    return 0;
}