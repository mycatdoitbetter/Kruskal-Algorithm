#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h" // 'INTERFACES'

struct graphs{
    int isWeighted;
    int numberOfVertices;
    int maxDegree;
    int** edges;
    float** weights;
    int* degree;
};

Graphs* createGraph(int numberOfVertices, int maxDegree, int isWeighted){
    Graphs *graphs;
    graphs = (Graphs*) malloc(sizeof(struct graphs));
    if(graphs != NULL){
        int i;
        graphs->numberOfVertices = numberOfVertices;
        graphs->maxDegree = maxDegree;
        graphs->isWeighted = (isWeighted != 0)?1:0;
        graphs->degree = (int*) calloc(numberOfVertices,sizeof(int));

        graphs->edges = (int**) malloc(numberOfVertices * sizeof(int*));
        for(i=0; i<numberOfVertices; i++)
            graphs->edges[i] = (int*) malloc(maxDegree * sizeof(int));

        if(graphs->isWeighted){
            graphs->weights = (float**) malloc(numberOfVertices * sizeof(float*));
            for(i=0; i < numberOfVertices; i++)
                graphs->weights[i] = (float*) malloc(maxDegree * sizeof(float));
        }

    }
    return graphs;
}

void freeFork(Graphs* graphs){
    if(graphs != NULL){
        int i;
        for(i=0; i<graphs->numberOfVertices; i++)
            free(graphs->edges[i]);
        free(graphs->edges);

        if(graphs->isWeighted){
            for(i=0; i<graphs->numberOfVertices; i++)
                free(graphs->weights[i]);
            free(graphs->weights);
        }
        free(graphs->degree);
        free(graphs);
    }
}

int insertsEdge(Graphs* graphs, int origin, int dest, int isDigraph, float peso){
    if(graphs == NULL)
        return 0;
    if(origin < 0 || origin >= graphs->numberOfVertices)
        return 0;
    if(dest < 0 || dest >= graphs->numberOfVertices)
        return 0;

    graphs->edges[origin][graphs->degree[origin]] = dest;
    if(graphs->isWeighted)
        graphs->weights[origin][graphs->degree[origin]] = peso;
    graphs->degree[origin]++;

    if(isDigraph == 0)
        insertsEdge(graphs,dest,origin,1,peso);
    return 1;
}

void Kruskal(Graphs *graphs, int origin, int *father){
    int i, j, dest, first, numberOfVertices = graphs->numberOfVertices;
    double lessWeight;
    int *arv = (int*) malloc(numberOfVertices * sizeof(int));
    for(i = 0; i < numberOfVertices; i++){
        arv[i] = i;
        father[i] = -1;
    }
    father[origin] = origin;
    while(1){
        first = 1;
        for(i = 0; i < numberOfVertices; i++){
            for(j = 0; j < graphs->degree[i]; j++){
                if(arv[i] != arv[graphs->edges[i][j]]){
                    if(first){
                        lessWeight = graphs->weights[i][j];
                        origin = i;
                        dest = graphs->edges[i][j];
                        first = 0;
                    }
                }
            }
        }
        if(first == 1) break;
        if(father[origin] == -1) father[origin] = dest;
        else father[dest] = origin;

        for(i = 0; i < numberOfVertices; i++){
            if(arv[i] == arv[dest]){
                arv[i] = arv[origin];
            }
        }
    }
}
