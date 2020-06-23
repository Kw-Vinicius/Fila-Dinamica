#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Tipo_Fila{
    int valor;
    struct Tipo_Fila *prox;
}Tipo_Fila;

Tipo_Fila *Primeiro;
Tipo_Fila *Ultimo;

void Fvazia(){
    Tipo_Fila *aux;
    aux = (Tipo_Fila*) malloc(sizeof(Tipo_Fila));
    Primeiro = aux;
    Ultimo = Primeiro;
}

void insere(int x){
    Tipo_Fila *novo;
    novo = (Tipo_Fila*)malloc(sizeof(Tipo_Fila));
    novo->valor = x;
    Ultimo->prox = novo;
    Ultimo = Ultimo->prox;
    novo->prox = Primeiro;
    if(Primeiro->prox == NULL){
        Primeiro->prox = Ultimo;
    }
}

void exibe(){
    Tipo_Fila *aux;
    int flag = 0;
    aux = Primeiro->prox;
    if(aux == NULL){
        printf("Fila vazia! Nada a exibir\n");
    }else{
        while(aux != Primeiro){
        printf("Item: %d\n",aux->valor);
        aux = aux->prox;
        }
    }
}

void procura(int x){
    Tipo_Fila *procurado;
    int flag = 0;
    procurado = Primeiro->prox;
    while(procurado != Primeiro){
        if(procurado->valor == x){
            printf("Acho item %d\n",x);
            flag = 1;
            procurado = Primeiro;
        }else{
            procurado = procurado->prox;
        }
    }
    if(flag == 0){
        printf("Não achou o item %d\n",x);
    }
}

void Remove(){
    Tipo_Fila *temp;
    temp = Primeiro->prox;
    if(temp == NULL){
        printf("Fila Vazia! Nada a remover\n");
    }else {
        Primeiro->prox = Primeiro->prox->prox;
        free(temp);
        printf("REMOVENDO\n");
    }
}

void apagar(){
    Tipo_Fila *temp;
    temp = Primeiro->prox;
    while(temp != Primeiro){
        Primeiro->prox = Primeiro->prox->prox;
        free(temp);
        temp = Primeiro->prox;
    }
    Primeiro->prox = NULL;
}

void menu(){
    int op = -1;
    int value;

    while(op != 0){
        system("clear");
        printf("0 - Sair\n");
        printf("1 - Adicionar elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Exibir a fila\n");
        printf("4 - Apagar a fila\n");
        printf("Digite sua opção: ");
        scanf("%d",&op);
        printf("\n");

        switch(op){
            case 0:
                break;
            case 1:
                printf("Digite um valor para adicionar a pilha: "); 
                scanf("%d",&value);
                insere(value);
                break;
            case 2:
                Remove();
                sleep(1.5);
                break;
            case 3:
                exibe();
                sleep(1.5);
                break;
            case 4:
                apagar();
                break;
            default:
                printf("Digite uma opção valida!\n");
                sleep(1.5);
        }
    }

}

int main(void){
    Fvazia();
    menu();
    apagar();
}