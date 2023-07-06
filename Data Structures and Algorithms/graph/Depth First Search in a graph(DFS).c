#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int item;
    struct node *next;
};

struct graph {
    int directed;
    struct node **vertices;
    bool *visited;
};

struct node* getnode(int item) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node){
        new_node->item = item;
        new_node->next = NULL;
    }
    return new_node;
}

struct graph* getgraph(int num_vertexes, int directed) {
    struct graph *new_graph = (struct graph*)malloc(sizeof(struct graph));
    if(new_graph){
        new_graph->vertices = (struct node**)malloc(num_vertexes * sizeof(struct node*));
        new_graph->visited = (bool*)malloc(num_vertexes * sizeof(bool));

        for(int i = 0 ; i < num_vertexes ; i++){
            new_graph->vertices[i] = NULL;
            new_graph->visited[i] = false;
        }
        new_graph->directed = directed;
    }
    return new_graph;
}

void addedge(struct graph *g, int vertex1, int vertex2) {
    struct node *vertex = getnode(vertex2);
    vertex->next = g->vertices[vertex1];
    g->vertices[vertex1] = vertex;

    if(!g->directed){
        vertex = getnode(vertex1);
        vertex->next = g->vertices[vertex2];
        g->vertices[vertex2] = vertex;
    }
}

void dfs(struct graph *g, int start, int end, int len, int *min_len) {
    if(start == end) {
        if(len < *min_len) {
            *min_len = len;
        }
        return;
    }
    g->visited[start] = true;
    struct node *current = g->vertices[start];

    while(current != NULL) {
        if(!g->visited[current->item]) {
            dfs(g, current->item, end, len + 1, min_len);
        }
        current = current->next;
    }
    g->visited[start] = false;
}

int main() {

    int num_vertexes, num_edges;
    int i, v1, v2, start, end;
    int min_len = 1000000;

    scanf("%d %d", &num_vertexes, &num_edges);
    struct graph *g = getgraph(num_vertexes, 1);

    for(i = 0 ; i < num_edges ; i++) {
        scanf("%d %d", &v1, &v2);
        addedge(g, v1, v2);
    }
    scanf("%d %d", &start, &end);
    dfs(g, start, end, 0, &min_len);
    printf("Tamanho do menor caminho de G: %d\n", min_len);

    return 0;
}