
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No{
   
    float cpf;
    
    //mecanismo p/ unir nos!
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add(float cpf, int pos){
    
    if(pos >= 0 && pos <= tam){
    
        NO * novo = malloc(sizeof(NO)); //calloc
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
        printf("CPF: %.0f\n", aux->cpf);
            aux = aux->prox;
    }
}


int main(){

    add(2938314545778457, 0);
    add(29848, 0);
    add(29646, 2);
    add(29133, 0);
    add(4444,  3);
    imprimir();
    
    printf("Gerando 10 valores aleatorios:\n\n");

    srand(time(NULL));

    for (int i = 0; i < 3; i++){

        printf("%d \n", rand() % 6);
    }
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i;
  
  printf("Gerando 10 valores aleatorios:\n\n");
  
  /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
  com o valor da função time(NULL). Este por sua vez, é calculado
  como sendo o total de segundos passados desde 1 de janeiro de 1970
  até a data atual.
  Desta forma, a cada execução o valor da "semente" será diferente.
  
  srand(time(NULL));
  
  for (i=0; i < 10; i++)
  {
    // gerando valores aleatórios na faixa de 0 a 100
    printf("%d ", rand() % 100);
  }
  
  return 0;
}
*/

