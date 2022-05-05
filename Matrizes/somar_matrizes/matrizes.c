#include <stdio.h>
#include <stdlib.h>

int main(){
    int linha, coluna, 
        primeira_matriz [3][3] =  { 1,2,3,    4,5,6,     7,8,9  },
        segunda_matriz  [3][3] =  { 2,3,4,    5,6,7,     8,9,10 },
        somar_matrizes  [3][3];

    for ( linha = 0; linha< 3; linha++){          //percorrer linha da matriz
        for ( coluna = 0; coluna < 3; coluna++){  //percorrer coluna da matriz

            somar_matrizes  [linha][coluna] =     //somar as matrizes
            primeira_matriz [linha][coluna] + 
            segunda_matriz  [linha][coluna];
        }
    }
    for ( linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){

            printf("%2d + %2d =  %2d \n", 
            primeira_matriz[linha][coluna],
            segunda_matriz [linha][coluna],
            somar_matrizes [linha][coluna]
            );
        }
    }
    return 0;
}
