#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

 typedef struct nodeItem{                        //item do nó
    int info;
    struct nodeItem *next;
}node;
 typedef struct {
    node *top;                                   // verificr topo da pllha 
 }stack;
 
 node *  newNode     (int info);                 //Alocar     um   novo  nó
 stack*  newStack    (        );
 void    push        (stack * s, int value);     // criar     novo item  da   pilha
 int     pop         (stack * s);                // retirar   item do    topo
 int     top         (stack * s);                // apontar   para item  do   topo
 int     isStackEmpty(stack * s);                // verificar se a pilha esta vazia

//------------------------------------------------------------
 int main(){
    stack *p;
    p = newStack();
    if (isStackEmpty(p)){
        printf("A pilha esta vazia\n");
    }
    push(p,80);
    push(p,70);
    printf("item topo atual:      %d\n   ", top(p)); //verificar item do topo
    printf("removeu item do topo: %d\n   ", pop(p)); //remover item do topo    
    printf("Novo item do topo:    %d\n   ", top(p)); //verificar item do topo                     
    
    if (isStackEmpty(p)){
        printf("A pilha esta vazia\n");
    }
 }
//------------------------------------------------------------
 stack *newStack(){
     stack  *p = (stack*)malloc(sizeof(stack));
     p->top = NULL;
     return  p;
 }
//------------------------------------------------------------
node*  newNode(int info){
    node *n = (node *)malloc(sizeof(node));
    n->info = info;
    n->next = NULL;
    return n;
}
//------------------------------------------------------------
 void push(stack *s, int value){
     node *n = newNode(value);
     n->next = s->top;
     s->top = n;
 }
//------------------------------------------------------------
 int pop(stack *s){
     int aux;
     node *n;
     if(isStackEmpty(s)){
        printf("A pilha esta vazia\n");
        return -1;
     }
     n      = s->top;
     aux    = n->info;
     s->top = n->next;
     free(n);
     return aux;
 }
//------------------------------------------------------------
 int top(stack  *s){
     if(isStackEmpty(s)){
        printf("A pilha esta vazia\n");
        return -1;
     }
     return s->top->info;
 }
//------------------------------------------------------------
 int isStackEmpty(stack *s){
     return s->top == NULL;
 }
//------------------------------------------------------------