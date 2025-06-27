#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main() {
    ofstream arquivo("cenagrafica.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return 1;
    }

    int opcao;
        cout << "\nEscolha a figura para adicionar:\n"<< endl;
        cout << "\n\t1 = Quadrado (lado)\n"<< endl;
        cout << "\n\t2 = Retangulo (base altura)\n" << endl;
        cout << "\n\t3 = Triangulo (base altura)\n"<< endl;
        cout << "\n\t4 = Cubo (lado)\n" << endl;
        cout << "\n\t5 = Paralelepipedo (largura altura profundidade)\n"<< endl;
        cout << "\n\t6 = Cilindro (raio altura)\n" << endl;
        cout << "\n\t7 = Cone (raio altura)\n" << endl;
        cout << "\n\t8 = Esfera (raio)\n" << endl;
        cout << "\n\t0 = Finalizar\n" << endl;
        cout << "\n\tOpção: " << endl;
        cin >> opcao;

        while (opcao != 0){
        if (opcao == 1) {
                float lado;
                cout << "Digite o lado do quadrado: ";
                cin >> lado;
                arquivo << "quadrado " << lado << endl;
                break;
                
            } else {
                if (opcao == 2) {
                    float base, altura;
                    cout << "Digite a base e altura do retangulo: ";
                    cin >> base >> altura;
                    arquivo << "retangulo " << base << " " << altura << endl;
                    break;
                    
                } else {
                    if (opcao == 3) {
                        float base, altura;
                        cout << "Digite a base e altura do triangulo: ";
                        cin >> base >> altura;
                        arquivo << "triangulo " << base << " " << altura << endl;
                        break;
                        
                    } else {
                        if (opcao == 4) {
                            float lado;
                            cout << "Digite o lado do cubo: ";
                            cin >> lado;
                            arquivo << "cubo " << lado << endl;
                            break;
                            
                        } else {
                            if (opcao == 5) {
                                float largura, altura, profundidade;
                                cout << "Digite a largura, altura e profundidade do paralelepipedo: ";
                                cin >> largura >> altura >> profundidade;
                                arquivo << "paralelepipedo " << largura << " " << altura << " " << profundidade << endl;
                                break;

                            } else {
                                if (opcao == 6) {
                                    float raio, altura;
                                    cout << "Digite o raio e altura do cilindro: ";
                                    cin >> raio >> altura;
                                    arquivo << "cilindro " << raio << " " << altura << endl;
                                    break;

                                } else {
                                    if (opcao == 7) {
                                        float raio, altura;
                                        cout << "Digite o raio e altura do cone: ";
                                        cin >> raio >> altura;
                                        arquivo << "cone " << raio << " " << altura << endl;
                                        break;

                                    } else {
                                        if (opcao == 8) {
                                            float raio;
                                            cout << "Digite o raio da esfera: ";
                                            cin >> raio;
                                            arquivo << "esfera " << raio << endl; 
                                            break;
                                        } else {
                                            if (opcao == 0) {
                                                cout << "\nFinalizando...\n" ;
                                                break;
                                        } else {
                                            cout << "\nOpcao invalida. Tente novamente.\n" ;                                                                 
                                            break;
                                            }     
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }    
   
   
        arquivo << "fim" << endl;
        arquivo.close();

        cout << "\nArquivo 'cenagrafica.txt' gerado com sucesso!\n";
        return 0;
   
   
    }   
