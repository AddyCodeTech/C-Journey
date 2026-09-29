#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* adj[100];

void addedge(int u, int v);
void dfs_h(int vertex, int* visited);
void dfs(int startVertex, int totalVertices);

int main() {
    int vertices, edges, u, v, source;
    
    printf("Enter the no. of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the no. of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < vertices; i++) {
        adj[i] = NULL;
    }
    
    printf("Enter the edges (u v):\n");
    for(int j = 0; j < edges; j++) {
        scanf("%d %d", &u, &v);
        addedge(u, v);
        addedge(v, u); 
    }

    printf("\nAdjacency List:\n");
    for(int i = 0; i < vertices; i++) {
        struct node* temp = adj[i];
        printf("Vertex %d: ", i);
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    printf("\nEnter the source vertex to start DFS: ");
    scanf("%d", &source);

    if (source >= 0 && source < vertices) {
        dfs(source, vertices);
    } else {
        printf("Invalid source vertex!\n");
    }

    for(int i = 0; i < vertices; i++) {
        struct node* temp = adj[i];
        while(temp != NULL) {
            struct node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }

    return 0;
}

void addedge(int u, int v) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = v;
    newnode->next = adj[u];
    adj[u] = newnode;
}

void dfs_h(int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct node* temp = adj[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (visited[adjVertex] == 0) {
            dfs_h(adjVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(int startVertex, int totalVertices) {
    int* visited = (int*)calloc(totalVertices, sizeof(int));

    printf("\nDFS Traversal starting from vertex %d: ", startVertex);
    dfs_h(startVertex, visited);
    printf("\n");
    
    free(visited);
}

