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
            no * aux = inicio; 

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

    int retorno; //criamos um inteiro para guardar o valor que vai ser desalocado do malloc

    if(pos >= 0 && pos < tam){ //note que por ser uma função para deletar, tem que parar antes do tamanho final, logo < tam. Pois o último elemento é = NULL (novo->prox = NULL)
        //1 - lista vazia
        if(inicio == NULL){ //condição desnecessária, pois nunca iremos querer apagar nada quando a lista for vazia, pois está vazia.
            printf("Lista vazia.\n");
        }

        //2 - queremos remover na pos 0 e a lista não está vazia
        else if(pos == 0){ //verificará se a pos = 0

            no *lixo = inicio; //criamos uma variável (que poderemos apagar depois) para percorrer a lista, logo chamamos de lixo

            if(tam == 1){ //único nó na lista
                inicio = NULL; //se a lista só tiver um elemento, inicio = NULL, pois irá apagar esse único elemento e esvaziar a lista
            }else{  //mais de um elemento da lista
                inicio = inicio->prox; //se quisermos apagar o primeiro elemento, é só definirmos o início como sendo a partir do segundo elemento
            }

        retorno = lixo->valor; //guardando numa variável o valor do nó q vai ser desalocado da memória
        free(lixo); //desalocando a variável da memória
        tam--; //diminuindo o tamanho da lista, já que deletou 1 elemento

        }else{

            no *aux = inicio; //criando variável auxiliar (de início)

            for(int i = 0; i < pos-1; i++){ //laço para percorrer a lista
                aux = aux->prox; //usando o auxiliar para percorrer a lista
            }
            //agora que chegamos na posição para nos auxiliar a remover a posição escolhida
            no *lixo = aux->prox; //chegando na posição, sefinimos como lixo o aux->prox, q é exatamente a posição q qremos remover
            aux->prox = lixo->prox; //chegando na posição selecionada para apagar
            //aux->prox = aux->prox->prox; //msm coisa da de cima


            retorno = lixo->valor; //novamente guardando o valor do ponteiro removido
            free(lixo); //desalocando o lixo (removendo)
            tam--; //diminuindo o tamamnho da lista, já q removemos um elemento

        }
        //3 - queremos remover no meio ou fim
    }

    return retorno; 
}

int main(){
    add(40, 0);
    add(30, 0);
    add(20, 0);
    add(10, 0);
    add(50, 2);
    delete(2);
    print_();



    return 0;
}