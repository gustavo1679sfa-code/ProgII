#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    int idade;
    float altura;

    cout << "Digite o nome completo: ";
    getline(cin, nome);

    cout << "Digite a idade: ";
    cin >> idade;

    cout << "Digite a altura: ";
    cin >> altura;

    cout << "\n Informações \n";
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Altura: " << altura << " m" << endl;

    return 0;
}
