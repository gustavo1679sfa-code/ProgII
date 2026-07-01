#include <iostream>
using namespace std;

class ContaBancaria {
private:
    int numeroConta;
    double saldo;

public:
    ContaBancaria(int numeroConta) {
        this->numeroConta = numeroConta;
        this->saldo = 0;
    }

    double getSaldo() {
        return saldo;
    }

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        }
    }

    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
        }
    }
};

int main() {
    ContaBancaria conta(12345);

    conta.depositar(100.0);
    conta.sacar(30.0);

    cout << "Saldo: " << conta.getSaldo() << endl;

    return 0;
}