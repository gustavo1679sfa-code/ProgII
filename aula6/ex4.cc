#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> palavras;
    string palavra;
    int quantidade;

    cout << "Quantas palavras deseja digitar? ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        cout << "Digite uma palavra: ";
        cin >> palavra;

        palavras.push(palavra);
    }

    return 0;
}