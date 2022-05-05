#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// função para criar a matriz ---------------------------------------

void **alocar_matriz(int linha, int coluna){

    srand(time(NULL));

    int i = 0, j = 0;
    int **matriz_dinamica = (int**)malloc(linha * sizeof(int*));

    for ( i = 0; i < linha; i++){
        matriz_dinamica[i] = (int*)malloc(coluna * sizeof(int));
    }
    for ( i = 0; i < linha; i++){
        for ( j = 0; j < coluna; j++){
            matriz_dinamica[i][j] = rand() % 100;
        }
    }

    return matriz_dinamica;
}



// função para imprimir a matriz ---------------------------------------

void imprimir_matriz(int **matriz_dinamica, int linha, int coluna){

    int i = 0 ,j = 0;
    for ( i = 0; i < linha; i++){
        for ( j = 0; j < coluna; j++){
            printf("%4.d", matriz_dinamica[i][j]);
        }
        printf("\n");
    }
    return 0;
}



// função para liberar a matriz ---------------------------------------

void liberar_matriz(int **matriz_dinamica, int linha, int coluna){

    int i = 0;
    for ( i = 0; i < linha; i++){

        free(matriz_dinamica[i]);
    }
    free(matriz_dinamica);
}



int main(){
    int **matriz_dinamica = NULL, linha, coluna, i;
    
    linha = coluna = i = 0;

    printf("\nInforme o numeros de linhas:");
    scanf("%d", &linha);
    printf("\nInforme o numeros de Colunas:");
    scanf("%d", &coluna);


    matriz_dinamica = alocar_matriz(linha, coluna);
    imprimir_matriz(matriz_dinamica, linha,coluna);
    liberar_matriz(matriz_dinamica, linha, coluna);

    return 0;
}

