// Prim's Algorithm
// key, mst and parent array 
#include <bits/stdc++.h>
using namespace std;

void primAlgo(int V, vector<pair<int, int>> adj[]) {
    vector<int> key(V + 1, INT_MAX);
    vector<bool> mst(V + 1, false);
    vector<int> parent(V + 1, -1);
    
    key[0] = 0;
    
    // min priority queue 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // key and node
    
    // traverse for n - 1 edges of the spanning tree 
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // for(int i = 0; i < V - 1; i++)
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        mst[u] = true;
        for(auto it: adj[u]) {
            int v = it.first;
            int w = it.second;
            
            if(mst[v] == false && w < key[v]) {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = w;
            }
        }
    }
    
    for(int i = 1; i < V; i++)
        cout << parent[i] << "->" << i << "\n";
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<pair<int, int>> adj[V];
    int u, v, w;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        
        // undirected graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    primAlgo(V, adj);
}
