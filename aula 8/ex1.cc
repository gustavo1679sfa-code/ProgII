#include <iostream>

using namespace std;

class MatrizDinamica {
private:
    int linhas;
    int colunas;
    int **matriz;

public:
    // Construtor parametrizado
    MatrizDinamica(int linhas, int colunas) {
        this->linhas = linhas;
        this->colunas = colunas;

        matriz = new int*[linhas];

        for (int i = 0; i < linhas; i++) {
            matriz[i] = new int[colunas];
        }
    }

    // Construtor de cópia: cópia profunda
    MatrizDinamica(const MatrizDinamica &outra) {
        linhas = outra.linhas;
        colunas = outra.colunas;

        matriz = new int*[linhas];

        for (int i = 0; i < linhas; i++) {
            matriz[i] = new int[colunas];

            for (int j = 0; j < colunas; j++) {
                matriz[i][j] = outra.matriz[i][j];
            }
        }
    }

    void setValor(int linha, int coluna, int valor) {
        matriz[linha][coluna] = valor;
    }

    void mostrarMatriz() {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destrutor: evita vazamento de memória
    ~MatrizDinamica() {
        for (int i = 0; i < linhas; i++) {
            delete[] matriz[i];
        }

        delete[] matriz;
    }
};

int main() {
    MatrizDinamica matriz1(2, 3);

    matriz1.setValor(0, 0, 10);
    matriz1.setValor(0, 1, 20);
    matriz1.setValor(0, 2, 30);
    matriz1.setValor(1, 0, 40);
    matriz1.setValor(1, 1, 50);
    matriz1.setValor(1, 2, 60);

    MatrizDinamica matriz2 = matriz1;

    cout << "Matriz copiada:" << endl;
    matriz2.mostrarMatriz();

    return 0;
}