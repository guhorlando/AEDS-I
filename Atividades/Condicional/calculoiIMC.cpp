#include <stdio.h>

int main () {
    float imc, peso, altura;

    //Entrada do código//
    printf("\n\tDigite seu peso: \n");
    scanf("%f", &peso);
    printf("\n\tDigite sua altura: \n");
    scanf("%f", &altura);

    //Processamento do código//
    imc = peso/altura*altura;
    
    //Saída do código//
    if (imc < 18.5){
        printf("\n\nBaixo Peso\n");
    } else {
    if (imc > 18,5 && imc < 24.5){
        printf("\n\nPeso normal\n");
    } else {
    if (imc > 25 && imc < 29.9){
        printf("\n\nSobrepeso\n");
    } else {
    if (imc > 30 && imc <34.9){
        printf("\n\nObesidade grau I\n");
    } else {
    if (imc > 35 && imc <34.9){
        printf("\n\nObesidade grau II\n");
    } else {
        printf("\n\nObesidade grau III\n");
                        }
                    }
                }
            }
        }
 
    return 0;
}
