#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_simples.h"


int main() {
    tipo_lista *L = criar_lista();
    insere_na_cabeca(L, 10);
    insere_na_cabeca(L, 20); 
    insere_na_cabeca(L, 30);
    insere_no_final(L, 11);
    insere_no_final(L, 12);
    insere_no_final(L, 13);
    imprime_lista(L);


    return 0; 
}