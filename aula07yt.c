#include <stdio.h>
#include <stdlib.h>

//criando a struct a ser usada
typedef struct no{
    int valor;
    
    struct no * prox;
}no;

//Caso base
no * inicio = NULL;
int tam = 0;

void add(int valor, int pos){
    //lógica!!! :D
    if(pos >= 0 && pos <= tam){ 

        no * novo = malloc(sizeof(no));
        novo->valor = valor;
        novo->prox = NULL; 

        //qual a posição eu coloco o no?

        //1 - lista vazia
        if(inicio == NULL){
            inicio = novo; 

        //2 - pos == 0 e lista NÃO vazia
        }else if(pos == 0){ 
            novo->prox = inicio;
            inicio = novo; 

        //3 - não ser no início da lista - meio ou fim    
        }else{
            no * aux = inicio; //definindo o endereço de variável pra onde queremos apontar, no caso, para o início

            for(int i = 0; i < pos-1; i++){ 
                aux = aux->prox; 
            }

            
            novo->prox = aux->prox; 
            aux->prox = novo; 
            
        }

        tam++;

    }
}

void print_(){
    no * aux = inicio;

        printf("\nImprimindo lista ...\n");
        for(int i = 0; i < tam; i++){ 
            printf("%d ", aux->valor);
            aux = aux->prox; 
        }
        printf("\n");
}

void delete(int pos){

    int retorno;
    if(pos >= 0 && pos < tam){
        //1 - lista vazia
        if(inicio == NULL){
            printf("Lista vazia.\n");
        }

        //2 - queremos remover na pos 0 e a lista não está vazia
        else if(pos == 0){
            no *lixo = inicio; //definindo o endereço de variável pra onde queremos apontar, no caso, para o início
            if(tam == 1){ //único nó na lista
                inicio = NULL;
            }else{  //mais de um elemento da lista
                inicio = inicio->prox;
            }

        retorno = lixo->valor;
        free(lixo);
        tam--;

        }else{
            no *aux = inicio; //definindo o endereço de variável pra onde queremos apontar, no caso, para o início
            for(int i = 0; i < pos-1; i++){
                aux = aux->prox;
            }
            no *lixo = aux->prox; //variável lixo sendo o prox de aux
            aux->prox = lixo->prox; //apagar
            //aux->prox = aux->prox->prox; //msm coisa da de cima


            retorno = lixo->valor;
            free(lixo);
            tam--;

        }
        //3 - queremos remover no meio ou fim
    }

    return retorno;
}

void alterar(int valor, int pos){
    no *aux = inicio; //definindo o endereço de variável pra onde queremos apontar, no caso, para o início
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }
    aux->valor = valor;

}

void search(int pos){
    
    no *aux = inicio; //definindo o endereço de variável pra onde queremos apontar, no caso, para o início
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }
    printf("%d\n", aux->valor);

}

int main(){
    add(40, 0);
    add(30, 0);
    add(20, 0);
    add(10, 0);
    add(50, 2);
    delete(2);
    //print_();
    search(2);



    return 0;
}