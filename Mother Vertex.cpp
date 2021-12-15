#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[start] = true;
    
    for(int next_node: adj[start]) {
        if(!vis[next_node]) {
            dfs(next_node, adj, vis);
        }
    }
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
    
    vector<bool> vis(v + 1, false);
    
    // apply dfs from all vertices of the connected graph
    int ans = 0;
    for(int i = 1; i <= v; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis);
            ans = i;
        }
    }
    
    // validate if ans is a mother vertex or not
    fill(vis.begin(), vis.end(), false);
    dfs(ans, adj, vis);
    for(int i = 0; i < v; i++) {
        if(vis[i] == false)
            return -1;
    }
    
    return ans;
}
