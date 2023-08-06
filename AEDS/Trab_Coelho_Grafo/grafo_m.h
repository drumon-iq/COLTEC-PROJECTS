#include <limits.h>
#include "commondef.h"
#include "fila.h"

typedef struct grafo{
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Grafo;

// Inicializa o grafo com um número específico de vértices
void criarGrafo(Grafo *grafo, int numVertices);

// Adiciona uma aresta entre dois vértices
void adicionarAresta(Grafo *grafo, int vertex1, int vertex2);

// Algoritmo de busca em largura (BFS) para encontrar o menor caminho entre dois vértices
void encontrarMenorCaminho(Grafo *grafo, int startVertex, int endVertex);
