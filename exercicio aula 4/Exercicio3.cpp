#include <iostream>
using namespace std;

inline double converterParaReais(double dolares, double cotacao) {
    return dolares * cotacao;
}

int main() {
    double dolares, cotacao, reais;

    cout << "Digite a quantia em dolares: ";
    cin >> dolares;

    cout << "Digite a cotacao do dolar: ";
    cin >> cotacao;

    reais = converterParaReais(dolares, cotacao);

    cout << "Valor convertido em reais: R$ " << reais << endl;

    return 0;
}