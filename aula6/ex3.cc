#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> documentos;
    string documento;
    int quantidade;

    cout << "Quantos documentos deseja inserir? ";
    cin >> quantidade;

    cin.ignore();

    for (int i = 0; i < quantidade; i++) {
        cout << "Digite o nome do documento: ";
        getline(cin, documento);

        documentos.push(documento);
    }

    return 0;
}