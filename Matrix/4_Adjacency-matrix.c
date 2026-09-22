#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* adj[10]; 

void addedge(int u, int v) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=v;
    newnode->next=adj[u];
    adj[u]=newnode;
}

int main() {
    int vertices, edges, u, v;
    printf("Enter the no. of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the no. of edges: ");
    scanf("%d", &edges);
    
    for(int i=0;i<vertices;i++) {
        adj[i]=NULL;
    }
    
    printf("\n\n");
    for(int j=0;j<edges;j++) {
        scanf("%d %d",&u,&v);
        addedge(u, v);
        addedge(v, u);
    }

    printf("\nAdjacency List:\n");
    for(int i=0;i<vertices;i++) {
        struct node* temp=adj[i];
        printf("Vertex %d: ", i);
        while(temp!=NULL) {
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
