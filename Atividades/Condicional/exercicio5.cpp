#include <stdio.h>

int main (){

    float nota;

    printf("Digite a nota: ");
    scanf("%f", &nota);

        if (nota >= 9 && nota <= 10){
            printf("Nota A");
        } else {
            if (nota >= 7 && nota <= 8.9){
                printf("Nota B");
            } else {
                if (nota >= 5 && nota <= 6.9){
                    printf("Nota C");
                } else {
                    if (nota >= 3 && nota <= 4.9){
                        printf("Nota D");
                    } else {
                        if (nota >= 0 && nota <= 2.9){
                            printf("Nota F");
                        } else{
                            printf("Nota não aceita!");
                        }
                    }
                }
            }
        }
    
                        
return 0;
}
