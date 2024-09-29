#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define INF INT_MAX

void printRoutingTable(vector<int>& dist, vector<int>& nextHop, int n, int src) {
    cout << "\nRouting table for router " << char('A' + src) << ":\n";
    cout << "Destination\tDistance\tNext Hop\n";
    for (int i = 0; i < n; i++) {
        char destination = char('A' + i);
        char hop = (nextHop[i] == -1) ? destination : char('A' + nextHop[i]);

        if (dist[i] == INF)
            cout << destination << "\t\tinf\t\t" << "-" << endl;
        else
            cout << destination << "\t\t" << dist[i] << "\t\t" << hop << endl;
    }
}

void distanceVectorRouting(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> nextHop(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                dist[i][j] = graph[i][j];
                nextHop[i][j] = j;
            }
        }
    }
    bool updated;
    do {
        updated = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][j] != INF && dist[j][k] != INF && dist[i][k] > dist[i][j] + dist[j][k]) {
                        dist[i][k] = dist[i][j] + dist[j][k];
                        nextHop[i][k] = nextHop[i][j];
                        updated = true;
                    }
                }
            }
        }
    } while (updated);
    for (int i = 0; i < n; i++) {
        printRoutingTable(dist[i], nextHop[i], n, i);
    }
}

int main() {
    int n, Edges;
    cout << "Enter the number of routers: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }
    cout << "Enter the number of edges: ";
    cin >> Edges;
    for (int i = 0; i < Edges; i++) {
        char srcChar, destChar;
        int weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> srcChar >> destChar >> weight;
        int src = srcChar - 'A';
        int dest = destChar - 'A';
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }
    distanceVectorRouting(graph, n);
    return 0;
}
