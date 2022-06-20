#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int cod;
    struct No *prox;
} NO;

// ponteiros globais
NO *inicio = NULL;
NO *fim = NULL;
tam = 0;

void add(int cod, int pos){
    
    NO *novo = malloc(sizeof(NO));
    novo -> cod = cod;
    novo -> prox = NULL;

    if(inicio == NULL){ //lista vazia
        inicio = novo;
        fim = novo;
        tam++;

        if(pos == 0){ //no inicio
            novo -> prox = inicio;
            inicio = novo;
            tam++;
        }

    }
    else{
        NO *aux = inicio;
        for(int i; i < pos - 1; i++){
            aux = aux->prox;
        }
        novo -> prox = aux -> prox;
        aux -> prox = novo;
        tam++;
    }
}

void remover(int cod, int pos){
    if (pos >= 0 && pos < tam){

    }
}
