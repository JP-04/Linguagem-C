#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 2
 typedef struct {
    int top;         // verificr topo da pllha 
    int data[N];     //dados da pilha
 }stack;

 stack*  newStack    (        );
 void    push        (stack * s, int value);     // criar     novo item  da   pilha
 int     pop         (stack * s);                // retirar   item do    topo
 int     top         (stack * s);                // apontar   para item  do   topo
 int     isStackEmpty(stack * s);                // verificar se a pilha esta vazia
 int     isStackFull (stack * s);                // veriricar se a pilha esta cheia 

//------------------------------------------------------------
 int main(){
    stack *p;
    p =   newStack();
    push(p,15);
    push(p,55);
    printf("Top: %d\n", pop(p));
    
    if (isStackEmpty(p)){
        printf("A pilha esta vazia\n");
    }
    if (!isStackFull(p)){
        printf("A pilha nao esta cheia\n");
    }
 }
//------------------------------------------------------------
 stack *newStack(){
     stack  *p = (stack*)malloc(sizeof(stack));
     p->top =0;
     return  p;
 }
//------------------------------------------------------------
 void push(stack *s, int value){
     if(isStackFull(s)){
         printf("Estouro de pilha\n");
         return;
     }
     s->data[s->top] = value;
     s->top++;
 }
//------------------------------------------------------------
 int pop(stack *s){
     if(isStackEmpty(s)){
        printf("A pilha esta vazia\n");
        return -1;
     }
     s->top = s->top - 1;
     return s->data[s->top];
 }
//------------------------------------------------------------
 int top(stack  *s){
     if(isStackEmpty(s)){
        printf("A pilha esta vazia\n");
        return -1;
     }
     return s->data[s->top - 1 ];
 }
//------------------------------------------------------------
 int isStackFull(stack *s){
    return s->top == N;
}
//------------------------------------------------------------
 int isStackEmpty(stack *s){
     return s->top ==0;
 }