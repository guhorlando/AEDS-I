#include <stdio.h>

int main()
{
    
    int numero, i;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    i = 1;

    printf("Numeros de 1 ate %d:\n", numero);

    while(i <= numero)
    {
        printf("%d ", i);
        i = i + 1;
    }
    printf("\n");

    i = 1;

    printf("\nOs numeros pares sao: \n", i);
    while (i <= numero){ 
        if (i % 2 == 0){
            printf("%d ", i);
        }
        i = i + 1;
    } 

    i = 1;

    printf("\nOs numeros impares sao: \n", i);
    while (i <= numero){
        if (i % 2 != 0){
            printf("%d ", i);
        
        }
        i = i + 1;
    }

    
    return 0;
}