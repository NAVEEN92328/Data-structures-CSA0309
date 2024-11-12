#include <stdio.h>
#include <stdlib.h>

#define V 4 
#define MAX_EDGES 5 

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x), rootY = find(subsets, y);
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskalMST(Edge edges[], int numEdges) {
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int e = 0, i = 0;
    while (e < V - 1 && i < numEdges) {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src), y = find(subsets, nextEdge.dest);

        if (x != y) {
            printf("%d - %d \t%d\n", nextEdge.src, nextEdge.dest, nextEdge.weight);
            unionSets(subsets, x, y);
            e++;
        }
    }
}

int main() {
    Edge edges[MAX_EDGES] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    printf("Minimum Spanning Tree using Kruskal's Algorithm:\n");
    kruskalMST(edges, MAX_EDGES);

    return 0;
}

