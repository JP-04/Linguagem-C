#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//------------------------------ valor armazenado e ponteiro 
typedef struct No{
    int        valor_lista;
    struct No *proximo_item;
}No;
//------------------------------ tamanho da lista e item do topo
typedef struct{
    No  *inicio;
    int tamanho_lista;
}Lista;
//------------------------------ inserir item no topo da lista
void inserir_topo(Lista *lista, int valor_lista){
    No     *novo           = (No *)malloc(sizeof(No));
    novo  -> valor_lista   = valor_lista;
    novo  -> proximo_item  = lista->inicio;
    lista ->inicio         = novo;
    lista ->tamanho_lista  ++; 
}
//------------------------------ inserir item no fim da lista
void inserir_final(Lista *lista, int valor_lista){
    No    *  no  , *novo   = (No *)malloc(sizeof(No));
    novo  -> valor_lista   = valor_lista;
    novo  -> proximo_item  = NULL;

    if( lista -> inicio == NULL){ //--- verificar se a lista esta vazia
        lista-> inicio  =  novo;      
    }
    else{
        no = lista->inicio;
        while (no->proximo_item != NULL){
            no = no->proximo_item;
        }
        no->proximo_item = novo;
    }
    lista->tamanho_lista++; 
}
//------------------------------ remover um item da lista
void remover_no_lista(Lista *lista, int valor_lista){
    No * inicio       = lista->inicio;
    No * remover_no   = NULL;

    if (inicio != NULL && lista->inicio->valor_lista == valor_lista){
        remover_no    = lista       ->  inicio;
        lista->inicio = remover_no  ->  proximo_item;
    }
    else{
        while (inicio != NULL && 
               inicio->proximo_item   != NULL &&
               inicio->proximo_item->valor_lista != valor_lista)
        {
            inicio = inicio->proximo_item; //percorrer lista
        }
        if (inicio != NULL && inicio->proximo_item != NULL)
        {
            remover_no           = inicio      -> proximo_item; //remover no
            inicio->proximo_item = remover_no  -> proximo_item; //remover item
        }
    }
    if (remover_no){
       free(remover_no);        //desalocar da mamoria
       lista->tamanho_lista--;  //remover da lista
    }
    
}

//------------------------------ mostrar lista
void imprimir_lista(Lista *lista){
    No    *inicio  = lista->inicio;
    printf("Tamanho da lista: %d \n", lista->tamanho_lista );
    while (inicio != NULL){
        printf("%d ", inicio->valor_lista);
        inicio =      inicio->proximo_item;
    }
    printf("\n\n");
}
//------------------------------

int main(){
    int opcao, valor;

    Lista lista;
    lista.inicio = NULL;
    lista.tamanho_lista = 0;    

    do{
        printf("\n------------- menu ------------- \n");
        printf(" 1 - Inserir no topo da lista \n 2 - Inserir no fim da lista \n 3 - Mostrar lista  \n 4 - Remover item da lista \n 5 - Sair do programa\n\n ---- opcao :");
        scanf("%d", &opcao);

        switch (opcao){
    //------------------------------    
        case 1:
            system("cls");
            printf("Informe um valor a ser inserido: ");
            scanf("%d", &valor);
            inserir_topo(&lista, valor);
            break;
    //------------------------------
        case 2:
            system("cls");
            printf("Informe um valor a ser inserido: ");
            scanf("%d", &valor);
            inserir_final(&lista, valor);
            break;
    //------------------------------
        case 3:
            imprimir_lista(&lista);
            break;
    //------------------------------
        case 4:
            system("cls");
            imprimir_lista(&lista);
            printf("\nInforme um valor a ser removido: ");
            scanf("%d", &valor);
            remover_no_lista(&lista, valor);
            break;
    //------------------------------
        case 5:
            printf("Finalizando........... ");
            break;
    //------------------------------
        default:
            printf("Opcao invalida");
            break;
        }

    } while (opcao != 5);    
    return 0;
}
