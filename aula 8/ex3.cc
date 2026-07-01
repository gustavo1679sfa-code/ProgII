#include <iostream>
#include <string>
#include <utility>

using namespace std;

class StringSegura {
private:
    string texto;

public:
    StringSegura() = default;

    StringSegura(string texto) {
        this->texto = texto;
    }

    // Impede cópia
    StringSegura(const StringSegura &outra) = delete;

    // Impede atribuição por cópia tradicional
    StringSegura& operator=(const StringSegura &outra) = delete;

    // Permite mover objetos em memória
    StringSegura(StringSegura &&outra) = default;

    // Permite atribuição por movimento
    StringSegura& operator=(StringSegura &&outra) = default;

    string getTexto() {
        return texto;
    }
};

int main() {
    StringSegura texto1("Direito e Programacao");

    StringSegura texto2 = move(texto1);

    cout << texto2.getTexto() << endl;

    return 0;
}