#include <stdio.h>
#define V 5
#define INF 9999

int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int count = 0; count < V-1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 8},
        {4, 0, 6, 0, 0},
        {0, 6, 0, 3, 0},
        {0, 0, 3, 0, 7},
        {8, 0, 0, 7, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
