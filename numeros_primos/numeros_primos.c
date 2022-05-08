#include <stdio.h>
#include <stdlib.h>

int numero_primo(int x){
    int i , divisores = 0;
    for ( i = 1; i <= x; i++){
        if (x % i == 0){
            divisores++;
        }
    }
    if(divisores == 2){
        return 1;           //retorna 1 para verdadeiro = primo
    }
    else{
        return 0;           //retorna 0 para falso      = não primo 
        }
}

int main(){
    int i;
    for ( i = 1; i <= 500; i++){
        if(numero_primo(i) == 1){
            printf("%d\n",i);
        }
    }
    return 0;
}
