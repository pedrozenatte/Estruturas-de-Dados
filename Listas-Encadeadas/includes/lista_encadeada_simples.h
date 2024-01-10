//#if !defined(LISTA_ENCADEADA_SIMPLES) outra maneira de escrever ifndef 
#ifndef LISTA_ENCADEADA_SIMPLES
#define LISTA_ENCADEADA_SIMPLES

//Estruturas
typedef struct _no tipo_no;
typedef struct _lista tipo_lista;

//Funções
tipo_lista *criar_lista();
tipo_no *criar_no(int valor);
void insere_na_cabeca(tipo_lista *L, int valor);
void imprime_lista(const tipo_lista *L);
void insere_no_final(tipo_lista *L, int valor);
int busca_elemento(const tipo_lista *L, int valor_buscado);
void remove_elemento(tipo_lista *L, int valor_removido);


#endif // LISTA_ENCADEADA_SIMPLES
