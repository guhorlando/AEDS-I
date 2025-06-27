#include <stdio.h>

int main () {
    int numero, fatorial, i;
    fatorial = 1;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    if (numero <= 0){
        return 1;
    }
    i = numero;
    printf("%d! = ", numero);


    while (i > 0){
        fatorial *= i;
        i = i - 1; 
        printf("%d", i);
        printf(" X ");
               
    }        

    printf (" = %d\n", fatorial);


    return 0;
}