#include <iostream>
using namespace std;

int main() {
    int num, soma = 0;

    cout << "Digite um numero inteiro positivo: ";
    cin >> num;

    if (num <= 0) {
        cout << "Numero invalido." << endl;
        return 0;
    }

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            soma += i;
        }

        if (soma > num) {
            break;
        }
    }

    if (soma == num) {
        cout << "Numero perfeito" << endl;
    } else {
        cout << "Nao é perfeito" << endl;
    }

    return 0;
}