#include <stdio.h>
#include <stdlib.h>

typedef struct No{
   
    double cpf;
    
    
    //mecanismo p/ unir nos!
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add(double cpf, int pos){
    
    if(pos >= 0 && pos <= tam){
    
        NO * novo = malloc(sizeof(NO));
        novo->cpf = cpf;
        novo->prox = NULL;
    
        if(inicio == NULL){ //lista vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else if(pos == 0){ //inicio
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(pos == tam){ //fim
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"
            
            NO * aux = inicio;
            for(int i = 0; i < pos-1; i++){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
            
        }
    
    }else{
        printf("deu ruim!!\n");
    }
}


void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Cod prod: %f\n", aux->cpf);
            aux = aux->prox;
    }
}


int main(){

    add(454688445548785, 0);
    add(29848, 0);
    add(29646, 2);
    add(29133, 0);
    add(44443, 3);
    add(54352, 0);
    imprimir();
    return 0;
}




  