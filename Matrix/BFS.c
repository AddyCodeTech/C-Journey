#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* adj[10]; 

void addedge(int u, int v) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = v;
    newnode->next = adj[u];
    adj[u] = newnode;
}

void bfs(int startVertex, int totalVertices) {
    int* visited = (int*)calloc(totalVertices, sizeof(int));
    int* queue = (int*)malloc(totalVertices * sizeof(int));
    int front = 0;
    int rear = 0;

    printf("\nBFS Traversal starting from vertex %d: ", startVertex);

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct node* temp = adj[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;

            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

int main() {
    int vertices, edges, u, v;
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

    if (vertices > 0) {
        bfs(0, vertices);
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
