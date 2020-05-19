#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

class Graph {
    public:
        Graph(int n) {
            edges.resize(n);
        }
    
        void add_edge(int u, int v) {
            edges[u].push_back(v); 
            edges[v].push_back(u); 
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> distance(edges.size(), -1);
            vector<bool> visited(edges.size(), false);
            std::queue<int> q;
            distance[start] = 0;
            q.push(start);
            visited[start] = true;
            while (!q.empty()){
                int v = q.front();
                q.pop();
                for (auto it = edges[v].begin(); it != edges[v].end(); it++) {
                    if (!(visited[*it])) {
                        q.push(*it);
                        visited[*it] = true;
                        distance[*it] = distance[v] + 6;
                    }
                }
            }
            return distance;
        }
    private:
        vector<list<int> > edges;
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}