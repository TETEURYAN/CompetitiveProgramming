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

void display(struct graph *g, int num_vertexes) {
    struct node *current = NULL;
    for(int i = 0 ; i < num_vertexes ; i++) {
        printf("[%d] ---> ", i);
        current = g->vertices[i];
        while(current != NULL) {
            if(current->next != NULL) {
                printf("%d -> ", current->item);
            }
            else {
                printf("%d", current->item);
            }
            current = current->next;
        }
        printf("\n");
    }
}
