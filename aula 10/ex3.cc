#include <iostream>
#include <string>

using namespace std;

class Veiculo {
public:
    string marca;

    virtual void emitirSom() {
        cout << "O veiculo faz um ruido generico de motor." << endl;
    }
};

class Carro : public Veiculo {
public:
    int numeroPortas;

    void emitirSom() override {
        cout << "Biiii biiii! O carro esta buzinando." << endl;
    }
};

int main() {
    Carro carro;

    carro.marca = "Fiat";
    carro.numeroPortas = 4;

    cout << "Marca: " << carro.marca << endl;
    cout << "Numero de portas: " << carro.numeroPortas << endl;

    carro.emitirSom();

    return 0;
}