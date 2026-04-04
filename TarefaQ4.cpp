#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    double salario;

    cout << "Digite o seu nome: ";
    getline(cin, nome);

    cout << "Digite o seu salario: ";
    cin >> salario;

    cout << "\n----- DADOS INFORMADOS -----\n";
    cout << "Nome: " << nome << endl;
    cout << "Salario: " << salario <<"R$"<< endl;
    cout << "----------------------------\n";

    return 0;
}
