#include "lista_encadeada_simples.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Estruturas da lista encadeada simples
typedef struct _no {
    int valor; 
    struct _no *proximo_no; 
} tipo_no;

typedef struct _lista {
    tipo_no *inicio; 
    int quantidade; //Guarda a quantidade de elementos da lista
    tipo_no *final; 
} tipo_lista;

//Função para criar uma lista
tipo_lista *criar_lista() { 
    tipo_lista *L = (tipo_lista *) calloc(1, sizeof(tipo_lista));
    L->inicio = NULL;
    L->final = NULL;
    L->quantidade = 0; //Boa prática de programação mesmo com utilizando o calloc

    return L; 
}

//Função para criar um nó da lista
tipo_no *criar_no(int valor) {
    tipo_no *no = (tipo_no *) calloc(1, sizeof(tipo_no));
    no->proximo_no = NULL;
    no->valor = valor;

    return no;
}

//Função para destruir lista
void destroi_lista(tipo_lista **L) {
    free(*L);
    *L = NULL; 
}

void destroi_no(tipo_no **no) {
    free(*no);
    *no = NULL; 
}

//Função para inserir em uma lista vazia
void insere_lista_vazia(tipo_lista *L, tipo_no *no) {
    L->inicio = no;
    L->final = no; 
    L->quantidade++;
}

//Função para adicionar um nó sempre no início da lista
void insere_na_cabeca(tipo_lista *L, int valor) {
    tipo_no *no = criar_no(valor); 

    //Vamos testar se a lista está vazia
    if(L->inicio == NULL) { //Lista vazia, podemos adicionar direto sem realizar nenhum tratamento
        insere_lista_vazia(L, no);
    }
    else { //Lista já possui pelo menos um elemento
        if(busca_elemento(L, valor) == -1){ //Elemento não foi inserido
            no->proximo_no = L->inicio;
            L->inicio = no; 
            L->quantidade++;
        }
        else{
            printf("Elemento ja inserido\n");
        }
    }
}

//Função para adicionar um nó sempre no final da lista
void insere_no_final(tipo_lista *L, int valor) {
    tipo_no *no = criar_no(valor);

    //Vamos testar se a lista está vazia
    if(L->inicio == NULL) { 
        insere_lista_vazia(L, no);
    }
    //Modo caso não existisse o ponteiro para o final direto
    /*
################################################################################################################
    else { //Caso haja algum elemento, então faremos o tratamento necessário para inserir no final
        tipo_no *aux = L->inicio;
        tipo_no *referencia; 

        while(aux != NULL){
            referencia = aux; 
            aux = aux->proximo_no;
        }
    //Após sair do while, o aux vai estar apontando para NULL e o referencia estará apontando para o último nó
    referencia->proximo_no = no; 
    L->final = no; 
    L->quantidade++;

    }
################################################################################################################
    */
    //OBS: Como já existe um ponteiro que vai diretamente para o final, pode-se utilizar dele para uma função mais rápida
    //Modo o qual se utiliza do ponteiro para o final
    else {
        if(busca_elemento(L, valor) == -1){
            L->final->proximo_no = no;
            L->final = no;
            L->quantidade++; 
        }
        else{
            printf("Elemento ja inserido\n");
        }
    }
}

//Função para imprimir a lista
void imprime_lista(const tipo_lista *L) { //const, pois só iremos fazer leitura, nenhuma modificação
    tipo_no *aux = L->inicio; //Nó auxiliar para percorrer a lista, haja vista a inexistência dos índices de vetores
    while(aux != NULL) {
        printf("%d ", aux->valor);

        aux = aux->proximo_no;
    } 
}

//Função para verificar se a lista está vazia
bool verifica_lista_vazia(const tipo_lista *L) {
    if(L->quantidade == 0) { //Se a quantidade de elementos presentes na lista for 0, então ela está vazia
        return true; 
    }
    else {
        return false; 
    }
}

//Função para buscar um elemento da lista
int busca_elemento(const tipo_lista *L, int valor_buscado) {
    //Vamos verificar se a lista está vazia
    if(verifica_lista_vazia(L)) {
        return -1; //Elemento não encontrado
    }
    else { 
        tipo_no *referencia = L->inicio; 
        int indice = 1; //Primeiro elemento

        while(referencia != NULL) {
            if(referencia->valor == valor_buscado) {
                return indice; //Elemento encontrado e está na posição indice
            }
            else {
                referencia = referencia->proximo_no;
                indice++;
            }
        }

        return -1; //Elemento não encontrado 
    }

}

//Função para remover elementos da lista independente de sua posição
void remove_elemento(tipo_lista *L, int valor_removido) {
    tipo_no *referencia_direita = L->inicio; //Guarda a referência do nó a ser apagado
    tipo_no *referencia_esquerda = NULL; //Guarda a referência do nó anterior ao que deve ser apagado

    int indice = busca_elemento(L, valor_removido); //Guarda o índice do elemento a ser removido

    //Vamos até o índice
    if(indice != -1) { //Significa que existe elemento para ser retirado
        printf("indice: %d\n", indice);
        for(int i = 0; i < indice; i++) {
            referencia_esquerda = referencia_direita;
            referencia_direita = referencia_direita->proximo_no;
        }
        //printf("Valor a ser removido: %d\n", referencia_direita->valor);
        //A partir do término do for, estamos exatamente no elemento a ser removido
        if(indice == 1) { //Estamos removendo o primeiro elemento
            L->inicio = referencia_direita->proximo_no;
            destroi_no(&referencia_direita);
        }
        else if(indice == L->quantidade) { //Estamos removendo o último elemento
            L->final = referencia_esquerda;
            destroi_no(&referencia_direita);
        }
        else { //Estamos removendo um elemento que está no meio da lista
            //Não precisamos nos preocupar com o ínicio e o fim da lista
            referencia_esquerda->proximo_no = referencia_direita->proximo_no;
            destroi_no(&referencia_direita);
        }
    }
    else{
        printf("Elemento inexistente\n");
    }
    
}