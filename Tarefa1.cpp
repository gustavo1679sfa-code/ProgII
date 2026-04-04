#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    int idade;

    cout << "Digite seu nome completo: ";
    getline(cin, nome);

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "\n Dados \n";
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;

    return 0;
}
