#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"
int main(){

    int isDigraph = 0;
    Graphs* graphs = createGraph(7, 500, 0);

    insertsEdge(graphs, 0, 5, isDigraph, 100);
    insertsEdge(graphs, 0, 3, isDigraph, 700);

    insertsEdge(graphs, 1, 3, isDigraph, 250);
    insertsEdge(graphs, 1, 2, isDigraph, 200);

    insertsEdge(graphs, 3, 4, isDigraph, 250);
    insertsEdge(graphs, 3, 2, isDigraph, 300);
    insertsEdge(graphs, 5, 3, isDigraph, 450);

    insertsEdge(graphs, 6, 5, isDigraph, 300);

    int i, father[7];
    Kruskal(graphs, 0, father);
    for(i = 0; i < 7; i++){
        printf("%d: %d\n", father[i], i);
     }
    printf("\n");
    system("pause");
    return 0;
}
