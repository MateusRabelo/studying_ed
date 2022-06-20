#include <stdio.h>
#include <stdlib.h>

//definindo um struct pessoa e seus dados
typedef struct aluno{
    int matricula;
    char nome[100];
    char end[100];
}aluno;

//definindo um struct para as notas dos alunos
typedef struct nota{
    double valor;
    char comentario[100];

}nota;

typedef struct no{
    aluno p;
    nota notas[100];
    double valor;

    struct no * prox;
}no;


no * inicio = NULL;
int tam = 0;

void add(int valor){
    no * novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->prox = NULL;
    
    if(inicio == NULL){
        inicio = novo;
        tam++;
    }

}








int main(){

    return 0;
}