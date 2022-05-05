#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tamanho , *array_dinamico;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    //numero aleatorio
    srand(time(NULL));
    // Definindo tamanho do array
    array_dinamico = (int *) calloc( tamanho,sizeof(int)); 

    if (array_dinamico){

        printf("memoria alocada com sucesso \n");

        for (int i = 0; i < tamanho; i++){ 

            // alocar numero aleatorio na memoria
            *(array_dinamico + i) = rand() % 100; 

            // mostrar memoria e numero alocado
            printf("Local da memoria %p: %d \n", array_dinamico[i],*(array_dinamico + i));
        }
    }
    //liberar memoria
    for (int i = 0; i < tamanho; i++){
         free(array_dinamico[i]);
    }free(array_dinamico);
    
    return 0;
}
