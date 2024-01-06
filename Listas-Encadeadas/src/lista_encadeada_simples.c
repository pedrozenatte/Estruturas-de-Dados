#include "lista_encadeada_simples.h"

typedef struct _no {
    int valor; 
    struct _no *proximo_no; 
} tipo_no;

typedef struct _lista {
    tipo_no *inicio; 
    int quantidade;
    tipo_no *final; 
} tipo_lista;