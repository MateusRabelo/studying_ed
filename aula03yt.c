#include <stdio.h>
#include <stdlib.h>


typedef struct no{ //definição de struct
    //qualquer informação pode vir dentro do nó
    //depende da aplicação
    int valor; 
    
    //mecanismo de ligação -> * ponteiros
    //?????????
    struct no * prox; //ponteiro que se liga ao endereço do próximo elemento, onde podemos começar uma lista encadeada.
}no;

int main(){

    no n1; //criação de variável n1 do tipo struct, onde está definindo o "int valor" da estrutura
    //printf("Endereco de N!: %p\n", &n1);
    n1.valor = 10; //definindo o ".valor" da estrutura

    no *p;
    p = &n1;

    no n2; //criação de variável n2 do tipo struct, onde está definindo o "int valor" da estrutura
    n2.valor = 5;

    no n3; //criação de variável n3 do tipo struct, onde está definindo o "int valor" da estrutura
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