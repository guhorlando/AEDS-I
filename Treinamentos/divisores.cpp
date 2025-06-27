#include <stdio.h>

int main () {
    int numero, i, contadorDivisores;
    i = 1;

    printf("Digite um número: ");
    scanf("%d", &numero);

    while (i <= numero){
        if (numero % i == 0){
            contadorDivisores = contadorDivisores + 1;
        }
        i = i + 1;       
    }

    if (contadorDivisores == 2){
        printf("\nO numero %d eh primo\n", numero);
    } else {
        printf("\nO numero %d nao eh primo\n", numero);
    }
    
    printf("\nO numero %d possui %d divisores\n", numero, contadorDivisores);
    
    return 0;
}