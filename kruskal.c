//used libraries
#include <stdio.h>
#include <stdlib.h>

//edge definition structure
typedef struct {
    int origin, destiny, value;
} Edge;

//graph definition structure
typedef struct {
    int V;
    int E;
    Edge* edge;
} Graph;

//function to create the graph
Graph* createGraph(int V, int E) {
    //dynamic graph allocation
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    
    graph->V = V;
    graph->E = E;
    //dynamic edge allocation
    graph->edge = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

//function to find
int find(int father[], int i) {
    if (father[i] == -1) {
        return i;
    }
    return find(father, father[i]);
}

//function to join
void join(int father[], int x, int y) {
    int xset = find(father, x);
    int yset = find(father, y);
    father[xset] = yset;
}

//function to compare
int compare(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->value - b1->value;
}

//function for Kruskal's algorithm
void Kruskal(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;
    
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);
    
    int* father = (int*)malloc(V * sizeof(int));
    
    for (int v = 0; v < V; v++) {
        father[v] = -1;
    }
    
    //definition that the graph must have n-1 edges
    while (e < V - 1 && i < graph->E) {
        Edge next = graph->edge[i++];
        int x = find(father, next.origin);
        int y = find(father, next.destiny);
        
        //being different, they do not form cycles
        if (x != y) {
            result[e++] = next;
            join(father, x, y);
        }
    }
    
    //frees memory allocation
    free(father);
    
    //shows the  minimum spanning tree
    printf("Arvore Geradora Minima:\n");
    for (int i = 0; i < e; i++) {
        printf("Origem: %d Destino: %d Peso: %d\n", result[i].origin, result[i].destiny, result[i].value);
    }
}

int main() {
    
    //get the number of vertices and adges
    int V, E;
    printf("Numero de vertices: ");
    scanf("%d", &V);
    printf("Numero de arestas: ");
    scanf("%d", &E);
    
    Graph* graph = createGraph(V, E);
    
    //obtains information about the edges and their weights from the user
    for (int i = 0; i < E; i++) {
        printf("Origem, destino, peso:");
        scanf("%d %d %d", &graph->edge[i].origin, &graph->edge[i].destiny, &graph->edge[i].value);
    }
    
    Kruskal(graph);
    
    return 0;
}
