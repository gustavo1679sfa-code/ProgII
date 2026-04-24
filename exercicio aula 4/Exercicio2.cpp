#include <iostream>
using namespace std;

int soma(int a, int b) {
    return a + b;
}

int main() {
    int valor1, valor2, resultado;

    cout << "Digite o primeiro valor inteiro: ";
    cin >> valor1;

    cout << "Digite o segundo valor inteiro: ";
    cin >> valor2;

    resultado = soma(valor1, valor2);

    cout << "Resultado da soma: " << resultado << endl;

    return 0;
}