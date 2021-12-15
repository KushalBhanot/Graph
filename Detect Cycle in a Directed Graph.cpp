#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int start, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& recStack) {
    if(!vis[start]) {
        vis[start] = true;
        recStack[start] = true;
        
        for(int next_node: adj[start]) {
            if(!vis[next_node] && isCyclic(next_node, adj, vis, recStack))
                return true;
            else if(recStack[next_node])
                return true;
        }
    }
    recStack[start] = false;
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> adj(v);
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        
        // directed graph
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    
    vector<bool> vis(v + 1, false);
    vector<bool> recStack(v + 1, false);
    for(int i = 1; i <= v; i++) {
        if(isCyclic(i, adj, vis, recStack))
            return true;
    }
    
    return false;
}
