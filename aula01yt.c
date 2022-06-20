#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{ //definição de struct
    int idade;
    float peso;
    float altura;
}pessoa; //definição de tipo como pessoa

int main(){

    pessoa p1, p2, p3; //definição das pessoas de struct pessoa
    printf("Qual a altura do paulo?\n");
    scanf("%f", p1.altura); //

    pessoa alunos[10]; //criação de vetor tamanho n para struct pessoa
    alunos[0] = p1; //definição de posição de vetor para pessoa1
    alunos[1] = p2; //definição de posição de vetor para pessoa2
    alunos[2] = p3; //definição de posição de vetor para pessoa3


    //impressões para demonstrações de valores de incluidos em struct pessoa
    printf("Altura: %f\n", p1.altura);
    printf("Peso: %f\n", p1.peso);
    printf("Idade: %d\n", p1.idade);

    printf("Altura: %f\n", p2.altura);
    printf("Peso: %f\n", p2.altura);
    printf("Idade: %d\n", p2.altura);

    return 0;  
}