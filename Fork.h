typedef struct fork Fork;

Fork* createFork(int numberOfVertices, int maxDegree, int isWeighted);

void freeFork(Fork* fork);

int insertsEdge(Fork* fork, int origin, int dest, int isDigraph, float peso);

void Kruskal(Fork *fork, int origin, int *father);
