typedef struct graphs Graphs;

Graphs* createGraph(int numberOfVertices, int maxDegree, int isWeighted);

void freeFork(Graphs* graphs);

int insertsEdge(Graphs* graphs, int origin, int dest, int isDigraph, float peso);

void Kruskal(Graphs *graphs, int origin, int *father);
