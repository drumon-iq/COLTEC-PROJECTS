#include "grafo_m.h"

void criarGrafo(Grafo *grafo, int numVertices) {
    grafo->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            grafo->matrix[i][j] = 0;
        }
    }
}

void adicionarAresta(Grafo *grafo, int vertex1, int vertex2) {
    if (vertex1 >= 0 && vertex1 < grafo->numVertices && vertex2 >= 0 && vertex2 < grafo->numVertices) {
        grafo->matrix[vertex1][vertex2] = 1;
        grafo->matrix[vertex2][vertex1] = 1;
    }
}

void encontrarMenorCaminho(Grafo *grafo, int startVertex, int endVertex) {
    bool visited[MAX_VERTICES] = {false};
    int parent[MAX_VERTICES];
    int distance[MAX_VERTICES];

    for (int i = 0; i < grafo->numVertices; i++) {
        parent[i] = -1;
        distance[i] = INT_MAX;
    }

    Fila q;
    initializarFila(&q);

    adc_Fila(&q, startVertex);
    visited[startVertex] = true;
    distance[startVertex] = 0;

    while (!filaVazia(&q)) {
        int currentVertex = rem_da_Fila(&q);

        for (int i = 0; i < grafo->numVertices; i++) {
            if (grafo->matrix[currentVertex][i] == 1 && !visited[i]) {
                adc_Fila(&q, i);
                visited[i] = true;
                parent[i] = currentVertex;
                distance[i] = distance[currentVertex] + 1;
            }
        }
    }

    if (!visited[endVertex]) {
        printf("Não há caminho entre os vértices %d e %d.\n", startVertex, endVertex);
    } else {
        printf("Caminho mais curto entre os vértices %d e %d: %d\n", startVertex, endVertex, distance[endVertex]);
        printf("Caminho: %d", endVertex);
        int temp = endVertex;
        while (parent[temp] != -1) {
            printf(" <- %d", parent[temp]);
            temp = parent[temp];
        }
        printf("\n");
    }
}
