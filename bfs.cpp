#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<bool>& vis) {
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        // if already visited
        if(vis[node] == true) continue;
        
        // visiting for the first time
        cout << node << " ";
        vis[node] = true;
        for(int i = 0; i < adj[node].size(); i++) {
            int next_node = adj[node][i];
            
            if(vis[next_node] == false)
                q.push(next_node);
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
    
    int start = 0;
    cin >> start;
    
    vector<bool> vis(v, false);
    bfs(start, adj, vis);
}
