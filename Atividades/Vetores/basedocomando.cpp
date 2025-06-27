#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    const int TAM = 20;

    ifstream arquivo("entrada.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }

    // Declaração de variáveis.
    float alturas[TAM], media, soma = 0;
    int i = 0;

    // Leitura do vetor.
    while (i < TAM && arquivo >> alturas[i]) {
        soma += alturas[i];
        i++;
    }

    arquivo.close();

    // Calcular a média.
    media = soma / i; // Dividir pelo número de valores lidos
    cout << fixed << setprecision(2);
    cout << "A média é: " << media << endl;

    int opcao = -1; // Inicializar a variável opcao
    do {
        // Exibir o menu de opções.
        cout << "\nMenu de Opções:\n";
        cout << "0. Sair\n";
        cout << "1. Calcular e exibir a média\n";
        cout << "2. Contar valores acima da média\n";
        cout << "3. Exibir todos os valores do vetor\n";
        cout << "4. Buscar um valor no vetor\n";
        cout << "5. Contar valores dentro de um intervalo\n";
        cout << "6. Inverta os valores do vetor\n";
        cout << "7. Adicione um valor para todos os elementos\n";
        cout << "8. Adicione um valor a todos os elementos não divisiveis por 3\n";
        cout << "9. Remover a 1ª ocorrência de um valor\n";
        cout << "10. Remover todas a ocorrências de um valor\n";
        cout << "11. Inserir um valor no vetor se não estiver cheio\n";
        cout << "12. Inserir um valor em uma determinada posição\n";
        cout << "13. Remover todos os valores repetidos\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                // Sair do programa.
                cout << "Saindo do programa..." << endl;
                break;

            case 1:
                // Exibir a média.
                cout << fixed << setprecision(2);
                cout << "A média é: " << media << endl;
                break;

            case 2: {
                // Contar valores acima da média.
                int acimaMedia = 0;
                for (int j = 0; j < i; j++) {
                    if (alturas[j] > media) {
                        acimaMedia++;
                    }
                }
                cout << "Valores acima da média: " << acimaMedia << endl;
                break;
            }

            case 3:
                // Exibir todos os valores do vetor.
                cout << "Valores do vetor: ";
                for (int j = 0; j < i; j++) {
                    cout << alturas[j] << " ";
                }
                cout << endl;
                break;

            case 4: {
                // Buscar um valor no vetor.
                float valorBusca;
                cout << "Digite um valor para buscar no vetor: ";
                cin >> valorBusca;

                int contador = 0;
                for (int j = 0; j < i; j++) {
                    if (alturas[j] == valorBusca) {
                        contador++;
                    }
                }

                cout << "O valor " << valorBusca << " foi encontrado " << contador << " vez(es) no vetor." << endl;
                break;
            }

            case 5: {
                // Contar valores dentro de um intervalo.
                float limiteInferior, limiteSuperior;
                cout << "Digite o limite inferior do intervalo: ";
                cin >> limiteInferior;
                cout << "Digite o limite superior do intervalo: ";
                cin >> limiteSuperior;

                int dentroIntervalo = 0;
                for (int j = 0; j < i; j++) {
                    if (alturas[j] >= limiteInferior && alturas[j] <= limiteSuperior) {
                        dentroIntervalo++;
                    }
                }

                cout << "Quantidade de valores no intervalo [" << limiteInferior << ", " << limiteSuperior << "]: " << dentroIntervalo << endl;
                break;
            }

            case 6: {
                // Inverter os valores do vetor.
                int inicio, fim;
                inicio = 0;
                fim = i - 1;
                
                while (inicio < fim) {
                    float temp = alturas[inicio];
                    alturas[inicio] = alturas[fim];
                    alturas[fim] =  temp;

                    inicio++;
                    fim--;
                }
                cout << "Vetor invertido: ";
                for (int j = 0; j < i; j++) {
                    cout << alturas[j] << " ";
                }
                cout << endl;
                break;
            }

            case 7: {
                // Adicionar valor para todos os elementos.
                int valor;
                cout << "Digite o valor a ser adicionado: \n";
                cin >> valor;
                
                for (int j = 0; j < i; j++) {
                    alturas[j] += valor;
                }
                cout << "Vetor atualizado: ";
                for (int j = 0; j < i; j++) {
                    cout << alturas[j] << " ";
                }
                cout << endl;
                break;
            }

            case 8: {
                // Adiocione um valor a todos os elementos não divisíveis por 3.
                int valor;
                cout << "Digite o valor a ser adicionado: ";
                cin >> valor;

                for (int j = 0; j < i; j++) {
                    if ((int)alturas[j] % 3 != 0) {
                        alturas[j] += valor;
                    }
                }
                    cout << "Vetor atualizado: ";
                    for (int j = 0; j < i; j++) {
                        cout << alturas[j] << " ";
                    }
                    cout << endl;
                    break;
                }

            case 9: {
                //Remover a primeira ocorrência de um valor
                int valor;
                cout << "Digite o valor a ser removido: ";
                cin >> valor;

                int pos = -1;

                for (int j = 0; j < i; j++) {
                    if (alturas[j] == valor) {
                        pos = j;
                        break;
                    }
                }

                if (pos != -1) {
                    for (int j = pos; j < i - 1; j++) {
                        alturas[j] = alturas [j + 1];
                    }
                    i--;
                    cout << "Valor removido!\nVetor atualizado: ";
                    for (int j = 0; j < i; j++) {
                        cout << alturas[j] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Valor não encontrado no vetor!" << endl;
                }
                break;
            }  
            
            case 10: {
            //Remover todas as ocorrências de um valor.
            int valor;
            cout << "Digite o valor a ser removido: ";
            cin >> valor;

            int j = 0;
            while (j < i) {
                if (alturas[j] == valor) {
                    for (int k = j; k < i - 1; k++) {
                        alturas[k] = alturas[k + 1];
                    }
                    i--; 
                } else {
                    j++;
                }
            }
            cout << "Todas as ocorrências removidas!\nVetor atualizado: ";
            for (int k = 0; k < i; k++) {
                cout << alturas[k] << " ";
            }
            cout << endl;
            break;
        }

            case 11: {
            //Inserir um valor no vetor, caso não esteja cheio.
            if (i < TAM) {
                int valor;
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                alturas[i] = valor;
                i++;
                cout << "Valor inserido!\nVetor atualizado: ";
                for (int j = 0; j < i; j++) {
                    cout << alturas[j] << " ";
                }
                cout << endl;
            } else {
                cout << "O vetor está cheio! Não é possível inserir mais valores." << endl;
            }
            break;
        }
               
            case 12: {
            //Inserir um valor em uma determinada posição.
            if (i < TAM) {
            int pos;
            float valor;
            cout << "Digite a posição (0 a " << i << ") para inserir o valor: ";
            cin >> pos;
            if (pos >= 0 && pos <= i) {
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                for (int j = i; j > pos; j--) {
                    alturas[j] = alturas[j - 1];
                }
                alturas[pos] = valor;
                i++;
                cout << "Valor inserido!\nVetor atualizado: ";
                for (int j = 0; j < i; j++) {
                    cout << alturas[j] << " ";
                }
                cout << endl;
            } else {
                cout << "Posição inválida!" << endl;
            }
        } else {
            cout << "O vetor está cheio! Não é possível inserir mais valores." << endl;
        }
        break;
    }

            case 13: {
            //Remover todos os valores repetidos.
            for (int j = 0; j < i; j++) {
            for (int k = j + 1; k < i; ) {
                if (alturas[j] == alturas[k]) {
                    for (int l = k; l < i - 1; l++) {
                        alturas[l] = alturas[l + 1];
                    }
                    i--;
                } else {
                    k++;
                }
            }
        }
        cout << "Valores repetidos removidos!\nVetor atualizado: ";
        for (int j = 0; j < i; j++) {
            cout << alturas[j] << " ";
        }
        cout << endl;
        break;
    }
     default:
        cout << "Opção inválida! Tente novamente." << endl;
        break;
        }
        
    } while (opcao != 0);

    return 0;
}