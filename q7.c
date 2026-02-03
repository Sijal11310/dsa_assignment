#include <stdio.h>


#define V 6 
#define INF 999999 //infinity 

// Function to find the vertex with the minimum weight value
int findMinDistance(int dist[], int visited[]) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the distance array
void printResult(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF){
            printf("%d \t INF\n", i);
        }
        else{
            printf("%d \t %d\n", i, dist[i]);
        }
    }
}

// Dijkstra logic
void dijkstra(int graph[V][V], int src) {
    int dist[V];    
    int visited[V]; 

    // Initialization
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of unvisited vertices
        int u = findMinDistance(dist, visited);

        if (u == -1) {
            break; // All remaining vertices are unreachable
        }

        visited[u] = 1;

        // Update distance value of the adjacent vertices
        for (int v = 0; v < V; v++) {
            // Relaxation condition
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printResult(dist);
}

int main() {
    //Weighted Graph as Adjacency Matrix
    int graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    dijkstra(graph, 0);

    return 0;
}