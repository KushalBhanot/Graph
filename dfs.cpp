#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[start] = true;
    
    for(int next_node: adj[start]) {
        if(!vis[next_node])
            dfs(next_node, adj, vis);
    }
    
    cout << start << " ";
}

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> adj(v);
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int start = 0;
    cin >> start;
    
    vector<bool> vis(v, false);
    dfs(start, adj, vis);
}
