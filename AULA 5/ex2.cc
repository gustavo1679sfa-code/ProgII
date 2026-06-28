#include <iostream>

using namespace std;

int main() {
    double a[100];
    double *aPtr = a;
    double soma = 0;
    int quantidade;

    cout << "Quantos valores deseja digitar? (maximo 100): ";
    cin >> quantidade;

    while (quantidade < 1 || quantidade > 100) {
        cout << "Quantidade invalida. Digite um numero entre 1 e 100: ";
        cin >> quantidade;
    }

    for (int j = 0; j < quantidade; j++) {
        cout << "Digite o valor " << j + 1 << ": ";
        cin >> *(a + j);
    }

    for (int j = 0; j < quantidade; j++) {
        soma += *(aPtr + j);
    }

    double media = soma / quantidade;

    cout << "\nSoma dos valores: " << soma << endl;
    cout << "Media dos valores: " << media << endl;

    return 0;
}