#include <stdio.h>
#include <stdbool.h>
#define MAX 20  

int n;      
int graph[MAX][MAX];
int color[MAX];    
int m;  
void printSolution() {
    printf("\nColor assigned to vertices:\n");
    for (int i = 0; i < n; i++)
        printf("Vertex %d - Color %d\n", i + 1, color[i]);
}

bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graphColoring(int v) {
    if (v == n) {
        printSolution();
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColoring(v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
        color[i] = 0;
    if (!graphColoring(0))
        printf("Solution does not exist with %d colors.\n", m);

    return 0;
}