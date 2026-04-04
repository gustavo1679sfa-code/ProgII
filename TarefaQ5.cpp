#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    int idade;
    float nota1, nota2, nota3, media;

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite a idade: ";
    cin >> idade;

    cout << "Digite a primeira nota: ";
    cin >> nota1;

    cout << "Digite a segunda nota: ";
    cin >> nota2;

    cout << "Digite a terceira nota: ";
    cin >> nota3;

    media = (nota1 + nota2 + nota3) / 3.0;

    cout << "\n----- DADOS DO ALUNO -----\n";
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "\n----- Notas -----\n";
    cout << "Primeira nota: " << nota1 << endl;
    cout << "Segunda nota: " << nota2 << endl;
    cout << "Terceira nota: " << nota3 << endl;
    cout << "\n----- Media -----\n";
    cout << "Media: " << media << endl;

    return 0;
}
