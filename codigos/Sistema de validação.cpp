#include <iostream>
using namespace std;

int main() {
    int idade, autorizacao, nivel;
    cout << "Digite a idade:";
    cin >> idade;

    cout <<"Tem autorização? (0 = não, 1 sim): ";
    cin >> autorizacao;

    cout <<"Digite o nivel (1 a 3): ";
    cin >> nivel;

    if (idade < 16){
        cout <<"Acesso negado" << endl;
        }
    else if (idade >= 16 && idade <= 17) {
        if (autorizacao == 1){
            cout << "Acesso autorizado com permissãom do responsavel." << endl;
        } else {
            cout << "Acesso negado, Precisa de autorização." << endl;

        }
    }
    else {
        switch (nivel) {
            case 1:
                cout << "Acesso basico." << endl;
                break;
            case 2:
                cout << "Acesso intermediario." << endl;
                break;
            case 3:
                cout << "Acesso Total." << endl;
                break;
            default:
                cout << "Erro: nivel inválido." << endl;

        }
    }
    return 0;
}