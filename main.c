#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define TAM 30

void main(){
    menu();
}

void menu(){
    char opcao = 'a';
    int quantidade = 0;
    while(opcao != '2'){
        system("clear");
        printf("Escolha uma das opções:\n");
        printf("1- Iniciar programa\n2- Sair\n");
        scanf("%c", &opcao);
        if(opcao == '1'){
            startProgram();
        }
    }
}

int startProgram(){
    int quantidade = 0, i = 0;
    printf("Bem - Vindo ao sistema!!!!\n");
    printf("\nDigite a quantidade de equações a serem inseridas: ");
    scanf("%d", &quantidade);
    char array[quantidade][TAM] ;
    for(i = 0; i < quantidade; i++){
        printf("Função %d:\n", i+1);
        scanf("%s", array[i]);
    }
    float **arrayCoefficient = returnArrayCoefficient(array, quantidade);

    return 0;
}

float *returnArrayCoefficient(char* equation, int quant){
    if(quant <= 0 || equation == NULL){
        return NULL;
    }
    char strEquation = equation[0];

    return NULL;
}