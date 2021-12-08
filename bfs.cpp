#include <bits/stdc++.h>
using namespace std;

#define MAX 1005;
vector<int> adj[MAX];

void bfs(int start, vector<bool>& vis) {
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
    
    for(int i = 0; i < e; i++) {
        int u, v;
        
        // directed graph
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    
    int start;
    cin >> start;
    vector<bool> vis(v + 1, false);
    bfs(start, vis);
}
