#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minDist(vector<int>& dist, vector<bool>& visited, int n) {
    int min = INT_MAX, index;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    return index;
}
/*
void print(const vector<int>& dist, int n) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout << char('A' + i) << "\t\t" << dist[i] << endl;
}*/

void print(vector<int>& dist, int n){
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

void dijkstra(vector<vector<int>>& graph, int src, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDist(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print(dist, n);
}

int main() {
    int n, Edges;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the number of edges: ";
    cin >> Edges;

  /*  for (int i = 0; i < Edges; i++) {
        char srcChar, destChar;
        int weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> srcChar >> destChar >> weight;
        int src = srcChar - 'A';
        int dest = destChar - 'A';
        graph[src][dest] = weight;
        graph[dest][src] = weight; // Assuming an undirected graph, remove this line if the graph is directed
    }

    char startChar;
    cout << "Enter Source vertex: ";
    cin >> startChar;
    int startVertex = startChar - 'A';
    */

    int startVertex;
    for (int i = 0; i < Edges; i++) {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> src >> dest >> weight;
        graph[src][dest] = weight;
    }
    cout << "Enter Source vertex: ";
    cin >> startVertex;

    dijkstra(graph, startVertex, n);

    return 0;
}
