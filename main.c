#include <stdio.h>
#include <stdlib.h>
#include "Fork.h"
int main(){

    int isDigraph = 0;
    Fork* fork = createFork(7, 650, 1);

    insertsEdge(fork, 0, 5, isDigraph, 200);
    insertsEdge(fork, 0, 3, isDigraph, 650);

    insertsEdge(fork, 1, 3, isDigraph, 350);
    insertsEdge(fork, 1, 2, isDigraph, 250);

    insertsEdge(fork, 3, 4, isDigraph, 300);
    insertsEdge(fork, 3, 5, isDigraph, 400);
    insertsEdge(fork, 3, 2, isDigraph, 600);

    insertsEdge(fork, 6, 5, isDigraph, 280);



    int i, father[6];
    Kruskal(fork, 0, father);
    for(i = 0; i < 6; i++){
        printf("%d: %d\n", father[i], i);
     }
    printf("\n");
    system("pause");
    return 0;
}
