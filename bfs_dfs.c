#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adj[20];
int visited[20], n;

void addEdge(int u, int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void BFS(int start) {
    int queue[20], front = 0, rear = 0;
    int seen[20] = {0};

    queue[rear++] = start;
    seen[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node *temp = adj[v];

        while (temp != NULL) {
            int u = temp->vertex;

            if (!seen[u]) {
                queue[rear++] = u;
                seen[u] = 1;
            }

            temp = temp->next;
        }
    }
    printf("\n");
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node *temp = adj[v];

    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(temp->vertex);

        temp = temp->next;
    }
}

int main() {
    int edges, u, v, start, i;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    for (i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v), vertices numbered 0 to %d:\n", n - 1);

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}