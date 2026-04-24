#include <iostream>
using namespace std;

int main(){
    int nA, nB;
    cout << "Qual o tamanho do vetor A:";
    cin >> nA;
    
    int A [nA];
    cout <<"Quais valores vai em A:";
    for (int i=0; i< nA; i++){
        cin >> A[i];
    }
    cout <<"Qual o tamanho do vetor B:";
    cin >> nB;
    int B[nB];
    cout << "Quais valores vai em B: ";
    for (int i=0; i <nB; i++){
        cin >> B[i];
    }

    int C[nA];
    int tamC = 0;
    bool existe;

    for (int i = 0; i < nA; i++){
        existe = false;

        for (int j = 0; j< nB; j++){
        if (A[i]==B[j]) {
            existe = true;
            break;
        }
    }
    if (!existe) {
        C[tamC] = A[i];
        tamC++;

        }
    }
    cout <<"Vetor C:\n ";
    for (int i = 0; i < tamC; i++){
        cout <<"[" << i << "]" << C[i] << endl;
    }
    cout << endl;

    return 0;
    }
