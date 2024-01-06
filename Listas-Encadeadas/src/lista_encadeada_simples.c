#include "lista_encadeada_simples.h"
#include <stdio.h>
#include <stdlib.h>

//Estruturas da lista encadeada simples
typedef struct _no {
    int valor; 
    struct _no *proximo_no; 
} tipo_no;

typedef struct _lista {
    tipo_no *inicio; 
    int quantidade;
    tipo_no *final; 
} tipo_lista;

//Função para criar uma lista
tipo_lista *criar_lista() { 
    tipo_lista *L = (tipo_lista *) calloc(1, sizeof(tipo_lista));
    L->inicio = NULL;
    L->final = NULL;

    return L; 
}

//Função para criar um nó da lista
tipo_no *criar_no(int valor) {
    tipo_no *no = (tipo_no *) calloc(1, sizeof(tipo_no));
    no->proximo_no = NULL;
    no->valor = valor;

    return no;
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
        no->proximo_no = L->inicio;
        L->inicio = no; 
        L->quantidade++;
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
        L->final->proximo_no = no;
        L->final = no;
        L->quantidade++;
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