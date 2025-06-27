#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string senha;
    string senhaCorreta = "algoritmo123";
    int i;

    cout << "Digite a senha: ";
    cin >> senha;
    i = 0;
    

    while (i < 2 && senha != senhaCorreta){
        cout << "Senha invalida!" << endl;
        cout << "Digite a senha: " << endl;
        cin >> senha;
        
        if (senha == "algoritmo123"){
            cout << "Acesso liberado!";
        } else {
            cout << "Acesso negado!";
        }
        i = i + 1;
    }
    

    
    













    return 0;
}