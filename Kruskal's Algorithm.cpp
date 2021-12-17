// Kruskal's Algorithm
// Greedy algorithm which uses Disjoint set data structure (rank and path compression)
// doesn't use an adjancent list, rather uses a linear data structure to store the elements
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int u;
    int v;
    int wt;
    
    Node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(Node a, Node b) {
    return a.wt < b.wt;
}

int findPar(int u, vector<int>& parent) {
    if(u == parent[u])
        return u;
    
    // path compression
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    
    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    // linear data structure for storing the elements
    vector<Node> edges;
    for(int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        
        edges.push_back(Node(u, v, wt));
    }
    
    sort(edges.begin(), edges.end(), comp);
    
    vector<int> parent(V + 1);
    vector<int> rank(V + 1, 0);
    for(int i = 0; i < V; i++) 
        parent[i] = i;
        
    vector<pair<int, int>> mst;
    int sumOfWeights = 0;
    for(auto it: edges) {
        // if they belong to different components
        if(findPar(it.u, parent) != findPar(it.v, parent)) {
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
            sumOfWeights += it.wt;
        }
    }
    
    cout << sumOfWeights << "\n";
    for(auto it: mst)
        cout << it.first << " - " << it.second << "\n";
        
    return 0;
}
