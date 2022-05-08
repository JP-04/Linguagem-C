#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>>

//Celula
typedef struct {
    int 
    bomba,           // verificar se a posicao eh uma bomba ou nao. 
    campo_aberto,    // verificar se a posicao esta aberta ou fechada
    campos_vizinhos; // verificar quantas bombas tem na vizinhanca 

}Celula;

Celula matriz_layout_jogo[10][10];
int    linha, coluna,tamanho = 10;

//inicizlizar a matriz do jogo 
void inicializar_jogo(){
    for (linha = 0; linha < tamanho; linha++){
        for (coluna = 0; coluna < tamanho; coluna++){            
            matriz_layout_jogo[linha][coluna].bomba           = 0;//0 = falso, 1 = verdadeiro
            matriz_layout_jogo[linha][coluna].campo_aberto    = 0;
            matriz_layout_jogo[linha][coluna].campos_vizinhos = 0;
        }
    }
}
// sortear N bombas
void sortear_bombas(int numeros_de_bombas){
    int i;
    srand(time(NULL));
    for (i = 0; i < numeros_de_bombas; i++){
        linha   = rand() % tamanho;                     //sortear linha
        coluna  = rand() % tamanho;                     //sortear coluna
        if (matriz_layout_jogo[linha][coluna].bomba == 0){
            matriz_layout_jogo[linha][coluna].bomba = 1;       //salvar bomba na linha e coluna sorteada
        }
        else{
            i--;  // repetir o laco se as bombas estiverem no mesmo lugar
        }
    }
}
// funcao que diz se um par der coordenadas eh valido ou nao 0 = falso, 1 = verdadeiro
int coordenada_valida(int linha, int coluna){
    if (linha >= 0 && linha <= tamanho && coluna >= 0 && coluna < tamanho){
        return 1; //coordenada valida
    }else{
        return 0; //coordenada invalida, exemplo: linha: -2 e coluna -1
    }
}
//funcao que retornar a quantidade_de_bombas de bombad na vizinhanca de linhae coluna
int quantidade_bombas_vizinhas(int linha, int coluna){
    int quantidade_de_bombas = 0;
    //verificar vizinho acima:          (linha - 1 e  coluna)
    if (coordenada_valida(linha - 1, coluna) && matriz_layout_jogo[linha - 1][coluna].bomba){
        quantidade_de_bombas++;
    }
    //verificar vizinho abaixo:         (linha + 1 e  coluna)
    if (coordenada_valida(linha + 1, coluna) && matriz_layout_jogo[linha + 1][coluna].bomba){
         quantidade_de_bombas++;
    }
    //verificar vizinho da direita:     (linha e coluna + 1)
    if (coordenada_valida(linha, coluna + 1) && matriz_layout_jogo[linha][coluna + 1].bomba){
        quantidade_de_bombas++;
    }
    //verificar vizinho da esquerda:    (linha e coluna - 1)
    if (coordenada_valida(linha, coluna - 1) && matriz_layout_jogo[linha][coluna - 1].bomba){
        quantidade_de_bombas++;
    }
    return quantidade_de_bombas;
}
//funcao para contar as bombas vizinhas
void contar_bombas_vizinhas(){

    for (linha = 0; linha < tamanho; linha++){
        for (coluna = 0; coluna < tamanho; coluna++){            
            matriz_layout_jogo[linha][coluna].campos_vizinhos = quantidade_bombas_vizinhas(linha,coluna);
        }
    }
}
// imprimir layout do jogo
void imprimir(){
    //repeticao para criar linhas
    printf("\n\n\t    ");
    for ( linha = 0; linha < tamanho; linha++){
        printf("  %d   ",linha); //indices das colunas
    }
    printf("\n\t   ------------------------------------------------------------\n");
    for (linha = 0; linha < tamanho; linha++){
        printf("\t%d  |",linha); //indices das linhas
        for (coluna = 0; coluna < tamanho; coluna++){
            if (matriz_layout_jogo[linha][coluna].campo_aberto){
                if (matriz_layout_jogo[linha][coluna].bomba){
                    printf(" * ");
                }
                else{
                    printf(" %d ", matriz_layout_jogo[linha][coluna].campos_vizinhos);
                }
            }
            else{
                printf("   ");
            }
            printf(" | ");
        }
            printf("\n\t   ------------------------------------------------------------\n");
     }
}
// funcao para abrir a coordenada digitada pelo usuario
void abrir_celula(int linha, int coluna){
    if (coordenada_valida(linha,coluna) == 1 && matriz_layout_jogo[linha][coluna].campo_aberto == 0){
        
        matriz_layout_jogo[linha][coluna].campo_aberto = 1;
        
        if (matriz_layout_jogo[linha][coluna].campos_vizinhos == 0){
                
            abrir_celula(linha - 1,coluna); //verificar vizinho acima
            abrir_celula(linha + 1,coluna); //verificar vizinho abaixo    
            abrir_celula(linha,coluna + 1); //verificar vizinho da direita
            abrir_celula(linha,coluna - 1); //verificar vizinho da esquerda
        }
    }
}
//funcao para verificar vitoria 1 = ganhou e 0 = perdeu
int ganhou(){
    int posicoes_fechadas = 0;
    for ( linha = 0; linha < tamanho; linha++){
        for (coluna = 0; coluna < tamanho; coluna++){
            if (matriz_layout_jogo[linha][coluna].campo_aberto == 0 && matriz_layout_jogo[linha][coluna].bomba == 0){
                posicoes_fechadas++;
            }
        }
    }
    return posicoes_fechadas;   
}
//funcao que faz as leituras das coordenadas
void jogar(){
    int linha, coluna;
    do{
        imprimir();
        do{
            printf("Informe a linha:");
            scanf("%d",&linha);
            printf("Informe a coluna:");
            scanf("%d",&coluna);

            if(coordenada_valida(linha,coluna) == 0){
                printf("coordenada invalida!!!\n");
            }
        }while (coordenada_valida(linha,coluna) == 0 || matriz_layout_jogo[linha][coluna].campo_aberto == 1);
         
        abrir_celula(linha,coluna);    
    }while (ganhou() != 0 && matriz_layout_jogo[linha][coluna].bomba == 0);

    if (matriz_layout_jogo[linha][coluna].bomba == 1){
        printf("burrao, voce perdeu \n");
    }
    else{
        printf("BOA BRABAO, VC GANHOU");
    }
    imprimir();
}
int main(){
    system("color 2f");
    int opcao;
    do
    {
        system("cls");
        inicializar_jogo();
        sortear_bombas(10);
        contar_bombas_vizinhas();
        printf("\n\tCAMPO MINADO!!!!!!!\n");
        jogar();

        printf("Digite 1 para jogar novamente:");
        scanf("%d", &opcao);

    }while(opcao == 1);

    return 0;
}
