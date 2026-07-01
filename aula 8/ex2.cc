#include <iostream>

using namespace std;

class Contador {
private:
    int valor;

public:
    Contador(int valor) {
        if (valor > 0) {
            this->valor = valor;
        } else {
            this->valor = 1;
        }
    }

    int getValor() {
        return valor;
    }

    // Pré-fixado: ++contador
    // Retorna uma referência ao objeto já incrementado.
    Contador& operator++() {
        ++valor;
        return *this;
    }

    // Pós-fixado: contador++
    // O int serve apenas para diferenciar esta assinatura.
    // Retorna uma cópia do objeto antes do incremento.
    Contador operator++(int) {
        Contador copia = *this;

        valor++;

        return copia;
    }
};

int main() {
    Contador contador(10);

    cout << "Valor inicial: " << contador.getValor() << endl;

    ++contador;
    cout << "Depois de ++contador: "
         << contador.getValor() << endl;

    contador++;
    cout << "Depois de contador++: "
         << contador.getValor() << endl;

    return 0;
}