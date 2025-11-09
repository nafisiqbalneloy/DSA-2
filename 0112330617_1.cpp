#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    int N;
    vector<vector<int>> adjMat;

public:
    Graph(int n) {
        N = n;
        adjMat = vector<vector<int>>(N, vector<int>(N, 0));
    }

    void addEdge(int u, int v, int w) {
        adjMat[u][v] = w;
        adjMat[v][u] = w; 
    }

    pair<int, vector<int>> dijkstra(int start, int end) {
        vector<int> dist(N, INT_MAX);
        vector<int> parent(N, -1);
        vector<bool> visited(N, false);

        dist[start] = 0;

        for (int count = 0; count < N - 1; count++) {
            int u = -1, minDist = INT_MAX;

            for (int i = 0; i < N; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < N; v++) {
                if (adjMat[u][v] != 0 && !visited[v] && dist[u] + adjMat[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMat[u][v];
                    parent[v] = u;
                }
            }
        }

        vector<int> path;
        for (int v = end; v != -1; v = parent[v])
            path.insert(path.begin(), v);

        return {dist[end], path};
    }

    void findPath(int S, int D) {
        auto result = dijkstra(S, D);
        cout << "Shortest time from " << S << " to " << D << ": " << result.first << endl;
        cout << "Path: ";
        for (int street : result.second) cout << street << " ";
        cout << endl;
    }

    void findPath(int S, int G, int D) {
        auto result1 = dijkstra(S, G);
        auto result2 = dijkstra(G, D);

        int totalTime = result1.first + result2.first;
        cout << "Shortest time from " << S << " to " << G << " to " << D << ": " << totalTime << endl;
        cout << "Path: ";
        for (int street : result1.second) cout << street << " ";
        for (int i = 1; i < result2.second.size(); i++) 
            cout << result2.second[i] << " ";
        cout << endl;
    }
};

int main() {
    int N = 6;
    Graph g(N);

    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    int S = 0, G = 2, D = 5;

    cout << "Direct path:\n";
    g.findPath(S, D);

    cout << "\nVia gas station:\n";
    g.findPath(S, G, D);

    return 0;
}
