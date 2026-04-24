#include <iostream>
using namespace std;

int main() {
    const int ANO = 2;
    const int TRIMESTRE = 4;

    double despesas[ANO][TRIMESTRE];
    double total = 0;

    for (int i = 0; i < ANO; i++) {
        cout << "Ano " << i + 1 << endl;

        for (int j = 0; j < TRIMESTRE; j++) {
            cout << "Despesa do trimestre " << j + 1 << ": ";
            cin >> despesas[i][j];
        }
    }

    cout << "\nDESPESAS\n";

    for (int i = 0; i < ANO; i++) {
        double totalAno = 0;

        cout << "\nAno " << i + 1 << ": ";

        for (int j = 0; j < TRIMESTRE; j++) {
            cout << despesas[i][j] << " ";
            totalAno = totalAno + despesas[i][j];
        }

        cout << " Total: R$ " << totalAno;

        total = total + totalAno;
    }

    cout << "\n\nTotal dos dois anos: R$" << total << endl;

    return 0;
}