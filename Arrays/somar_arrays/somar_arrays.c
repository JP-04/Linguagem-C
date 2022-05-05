#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i , primeiro_array[5], segundo_array[5] , somar_arrays[5];
    srand(time(NULL)); // sortear numeros dos vetores

    for ( i = 0; i < 5; i++){
        primeiro_array [i] = rand() % 50;   
        segundo_array  [i] = rand() % 50; 
    }
    for ( i = 0; i < 5; i++){
        somar_arrays   [i] = 
        primeiro_array [i] +
        segundo_array  [i]; 
    }

    printf("\n Array1: ");
    for ( i = 0; i < 5; i++){
        printf("%2d ", primeiro_array[i]);
    }
    printf("\n Array2: ");
    for ( i = 0; i < 5; i++){
        printf("%2d ", segundo_array[i]);
    }
    printf("\n Soma  : ");
    for ( i = 0; i < 5; i++){
        printf("%2d ", somar_arrays[i]);
    }
    return 0;
}




