#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor; 
    
    struct no * prox; //ponteiro que se liga ao endereço do próximo elemento, onde podemos começar uma lista encadeada.
}no;

//VARIÁVEIS GLOBAIS
no * inicio = NULL; //temos que começar a lista de algum lugar, e endereçamos o ponteiro para o "NULL - vazio"
int tam = 0; //variável que conta quantos elementos tem na lista

void add(int valor){
    //lógica!!! :D
    no * novo = malloc(sizeof(no)); //criando um struct *novo, onde será alocado os tamanho da struct inteira, como nó. Nosso struct é composto por um tipo inteiro ("int")

    //mexendo com "novo" e valores em ponteiros
    novo->valor = valor; //colocamos uma seta para o suposto "novo" elemento "struct" receber o valor do elemento endereçado
    novo->prox = NULL; //e conseguinte colocamos o suposto "novo" elemento "struct" receber o endereço do próxim elemento como "NULL"

    //de uma forma burra e nada dinâmica (com elementos decididos e estáticos), seria:
    /* no novo; //aqui criamos "novo" sem ponteiro nenhum, não alocando em lugar nenhum, o que ocasionará num problema de perca de elemento na memória, já que o malloc não vai estar apontando.
    novo.valor = valor; //recebe valor de novo
    novo.prox = NULL //atualiza o valor do próximo elemento para NULL. */

    if(inicio == NULL){ //quando a lista não tem elementos, ele entra aqui, onde se inicia tudo, já que o "incio" = NULL
        inicio = novo; //algo tem que gardar o valor de endereço do antigo "novo", e esse seria o novo início, exemplificando:  [NULL], incia do elemento NULL, se colocamos algo, o novo início é o elemento que incluímos
        tam++; //no final, temos que incluir o tamanho, para sabermos o tamanho da nossa lista (qunatos elementos temos) 
    }


}

void remove(int valor){

}

void search(){

}

int main(){

    no n1; 
    n1.valor = 10; 

    no *p;
    p = &n1;

    no n2;
    n2.valor = 5;

    no n3;
    n3.valor = 7;

    /*
    int i = 10;
    int * p; //criando variável de ponteiro relacionado ao tipo definido, que irá guardar (* <- apontar) a informação no endereço de memória, nomeada de "p"
    p = &i; //quando temos um ponteiro, temos que usar o "&" para buscar o endereço de memória
    */

    printf("Endereco de memoria armazenado na variavel p: %p\n", p); // "p" é um ponteiro, e ponteiros guardam endereços RAM, e aqui ele mostra o endereço de memória q a variável "p" apontando (armazennando)
    printf("Valor que esta no endereco de memoria armazenado na variavel p: %d\n", *p); //o endereço que "p" aponta guarda valores, e através do ponteiro (*), podemos acessar esses valores
    printf("O endereco de memoria de p: %p\n", &p); //"p" guarda o endereço apontado, mas também tem o seu próprio endereço de memória

    return 0;
}