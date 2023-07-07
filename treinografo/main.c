#include <stdio.h>
#include <stdlib.h>
#include "Estruturasdografo.h"

int main(){
int i;
char a = 'A', b = 'B', c = 'C', d = 'D';
Vert* grafo = NULL;
Lista* itens = NULL;

grafo = incluir_vertice(a,1,grafo);
grafo = incluir_vertice(b, 2, grafo);
grafo = incluir_vertice(c, 3, grafo);
grafo = incluir_vertice(d, 4, grafo);
inclui_aresta(a,b,20,grafo);
inclui_aresta(a,d,10,grafo);
inclui_aresta(b,c,30,grafo);
inclui_aresta(c,d,30,grafo);

itens = insere_lista(itens, d, grafo);
itens = insere_lista(itens, c, grafo->prox);
i = busca_lista(itens,d);

}
