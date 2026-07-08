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

int main() {
    Veiculo veiculo;

    veiculo.marca = "Honda";

    cout << "Marca: " << veiculo.marca << endl;
    veiculo.emitirSom();

    return 0;
}