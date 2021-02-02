#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"
int main(){

    int isDigraph = 0;
    Graphs* graphs = createGraph(7, 650, 1);

    insertsEdge(graphs, 0, 5, isDigraph, 200);
    insertsEdge(graphs, 0, 3, isDigraph, 650);

    insertsEdge(graphs, 1, 3, isDigraph, 350);
    insertsEdge(graphs, 1, 2, isDigraph, 250);

    insertsEdge(graphs, 3, 4, isDigraph, 300);
    insertsEdge(graphs, 3, 5, isDigraph, 400);
    insertsEdge(graphs, 3, 2, isDigraph, 600);

    insertsEdge(graphs, 6, 5, isDigraph, 280);



    int i, father[6];
    Kruskal(graphs, 0, father);
    for(i = 0; i < 6; i++){
        printf("%d: %d\n", father[i], i);
     }
    printf("\n");
    system("pause");
    return 0;
}
