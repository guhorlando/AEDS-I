#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

using namespace std;

const float PI= 3.14159265358979323846;

int main() {
    ifstream arquivo("cenagrafica_1.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }

    string figura;
    float area_total = 0.0;
    float volume_total = 0.0;

    while (arquivo >> figura) {
        if (figura == "fim") {
            break;
        } else {
            if (figura == "quadrado") {
                float lado;
                arquivo >> lado;
                area_total = lado * lado;
            
        } else {
            if (figura == "retangulo") {
                float base, altura;
                arquivo >> base >> altura;
                area_total = base * altura;
            } else {
                if (figura == "triangulo") {
                    float base, altura;
                    arquivo >> base >> altura;
                    area_total = (base * altura) / 2.0;
                } else {
                    if (figura == "cubo") {
                        float lado;
                        arquivo >> lado;
                        area_total = 6 * lado * lado;
                        volume_total = lado * lado * lado;
                    } else {
                        if (figura == "paralelepipedo") {
                            float largura, altura, profundidade;
                            arquivo >> largura >> altura >> profundidade;
                            area_total = 2 * (largura*altura + largura*profundidade + altura*profundidade);
                            volume_total = largura * altura * profundidade;
                        } else {
                            if (figura == "cilindro") {
                                float raio, altura;
                                arquivo >> raio >> altura;
                                area_total = 2 * PI * raio * (raio + altura);
                                volume_total = PI * raio * raio * altura;
                            } else {
                                if (figura == "cone") {
                                    float raio, altura;
                                    arquivo >> raio >> altura;
                                    float geratriz = (raio*raio + altura*altura);
                                    area_total = PI * raio * (raio + geratriz);
                                    volume_total = (PI * raio * raio * altura) / 3.0;
                                } else {
                                    if (figura == "esfera") {
                                        float raio;
                                        arquivo >> raio;
                                        area_total = 4 * PI * raio * raio;
                                        volume_total = (4.0/3.0) * PI * raio * raio * raio;
                                    } else {
                                      cout << "Figura desconhecida no arquivo: " << figura << endl;
                                    
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

    arquivo.close();

    cout << fixed << setprecision(2);
    cout << "\nResultados da cena grafica:\n";
    cout << "Area total: " << area_total << endl;
    cout << "Volume total: " << volume_total << endl;

    return 0;
}
