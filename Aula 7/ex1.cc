#include <iostream>
#include <string>

using namespace std;

class Gato {
private:
    string nome;
    int idade;
    double peso;

public:
    Gato(string nome, int idade, double peso) {
        this->nome = nome;
        this->idade = idade;

        if (peso > 0) {
            this->peso = peso;
        } else {
            this->peso = 1;
        }
    }

    void setPeso(double peso) {
        if (peso > 0) {
            this->peso = peso;
        }
    }
};

int main() {
    Gato gato("Mingau", 2, 4.5);

    gato.setPeso(5.0);
    gato.setPeso(-2.0);

    return 0;
}