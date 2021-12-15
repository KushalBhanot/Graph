#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    
    for(int next_node: adj[node]) {
        if(!vis[next_node])
            if(isCyclic(next_node, node, adj, vis)) return true;
        else if(next_node != parent)
            return true;
    }
    
    return false;
}

bool checkCycle(int v, vector<vector<int>>& adj) {
    vector<bool> vis(v + 1, false);
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            if(isCyclic(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> adj(v + 1);
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        
        // undirected graph
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    bool ans = checkCycle(v, adj);
    if(ans)
        cout << "Cyclic";
    else
        cout << "Not Cyclic";
}
