#include <stdio.h>
#include <stdlib.h>
#include "Fork.h" // 'INTERFACES'

struct fork{
    int isWeighted;
    int numberOfVertices;
    int maxDegree;
    int** edges;
    float** weights;
    int* degree;
};

Fork* createFork(int numberOfVertices, int maxDegree, int isWeighted){
    Fork *fork;
    fork = (Fork*) malloc(sizeof(struct fork));
    if(fork != NULL){
        int i;
        fork->numberOfVertices = numberOfVertices;
        fork->maxDegree = maxDegree;
        fork->isWeighted = (isWeighted != 0)?1:0;
        fork->degree = (int*) calloc(numberOfVertices,sizeof(int));

        fork->edges = (int**) malloc(numberOfVertices * sizeof(int*));
        for(i=0; i<numberOfVertices; i++)
            fork->edges[i] = (int*) malloc(maxDegree * sizeof(int));

        if(fork->isWeighted){
            fork->weights = (float**) malloc(numberOfVertices * sizeof(float*));
            for(i=0; i < numberOfVertices; i++)
                fork->weights[i] = (float*) malloc(maxDegree * sizeof(float));
        }

    }
    return fork;
}

void freeFork(Fork* fork){
    if(fork != NULL){
        int i;
        for(i=0; i<fork->numberOfVertices; i++)
            free(fork->edges[i]);
        free(fork->edges);

        if(fork->isWeighted){
            for(i=0; i<fork->numberOfVertices; i++)
                free(fork->weights[i]);
            free(fork->weights);
        }
        free(fork->degree);
        free(fork);
    }
}

int insertsEdge(Fork* fork, int origin, int dest, int isDigraph, float peso){
    if(fork == NULL)
        return 0;
    if(origin < 0 || origin >= fork->numberOfVertices)
        return 0;
    if(dest < 0 || dest >= fork->numberOfVertices)
        return 0;

    fork->edges[origin][fork->degree[origin]] = dest;
    if(fork->isWeighted)
        fork->weights[origin][fork->degree[origin]] = peso;
    fork->degree[origin]++;

    if(isDigraph == 0)
        insertsEdge(fork,dest,origin,1,peso);
    return 1;
}

void Kruskal(Fork *fork, int origin, int *father){
    int i, j, dest, first, NV = fork->numberOfVertices;
    double lessWeight;
    int *arv = (int*) malloc(NV * sizeof(int));
    for(i = 0; i < NV; i++){
        arv[i] = i;
        father[i] = -1;
    }
    father[origin] = origin;
    while(1){
        first = 1;
        for(i = 0; i < NV; i++){
            for(j = 0; j < fork->degree[i]; j++){
                if(arv[i] != arv[fork->edges[i][j]]){
                    if(first){
                        lessWeight = fork->weights[i][j];
                        origin = i;
                        dest = fork->edges[i][j];
                        first = 0;
                    }
                }
            }
        }
        if(first == 1) break;
        if(father[origin] == -1) father[origin] = dest;
        else father[dest] = origin;

        for(i = 0; i < NV; i++){
            if(arv[i] == arv[dest]){
                arv[i] = arv[origin];
            }
        }
    }
}
