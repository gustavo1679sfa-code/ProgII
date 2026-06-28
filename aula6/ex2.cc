#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> lista;
    int opcao, valor;

    do {
        cout << "\n1 - Inserir no inicio";
        cout << "\n2 - Inserir no final";
        cout << "\n3 - Remover valor";
        cout << "\n4 - Exibir tamanho da lista";
        cout << "\n0 - Sair";
        cout << "\nOpcao: ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite o valor: ";
            cin >> valor;

            lista.push_front(valor);
        }

        else if (opcao == 2) {
            cout << "Digite o valor: ";
            cin >> valor;

            lista.push_back(valor);
        }

        else if (opcao == 3) {
            cout << "Digite o valor que deseja remover: ";
            cin >> valor;

            lista.remove(valor);
        }

        else if (opcao == 4) {
            cout << "Tamanho da lista: " << lista.size() << endl;
        }

    } while (opcao != 0);

    return 0;
}