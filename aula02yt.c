#include <stdio.h>
#include <stdlib.h>


typedef struct pessoa{ //definição de struct
    int idade;
    float peso;
    float altura;
    
}pessoa; //definição de tipo como pessoa

int x = 5445022;
int y = 45;

int main(){

    pessoa p1;
    p1.peso = 60;
    p1.altura = 1.6;
    p1.idade = 20;


    printf("Valor da variavel: %d\n", p1.idade);
    printf("Endereco da variavel: %p\n", &p1);
    printf("Quantos bytes utiliza uma pessoa: %lu", sizeof(pessoa));
    
    return 0;
}