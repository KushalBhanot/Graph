// shortest path in a weighted DAG
// 1) Initialize dist[] = {INF, INF, ….} and dist[s] = 0 where s is the source vertex. 
// 2) Create a topological order of all vertices. 
// 3) Do following for every vertex u in topological order. 
// ………..Do following for every adjacent vertex v of u 
// ………………if (dist[v] > dist[u] + weight(u, v)) 
// ………………………dist[v] = dist[u] + weight(u, v) 

#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<bool>& vis, stack<int>& st, vector<pair<int, int>>& adj[]) {
    vis[node] = true;
    
    for(int next_node: adj[node]) {
        if(!vis[next_node])
            topoSort(next_node, vis, st, adj);
    }
    st.push(node);
}

void shortestPath(int src, int V, vector<pair<int, int>>& adj[]) {
    stack<int> st;
    vector<bool> vis(V + 1, false);
    
    for(int i = 0; i < V; i++) {
        if(!vis[i])
            topoSort(i, vis, st, adj);
    }
    
    vector<int> dis(V + 1, INT_MAX);
    dis[src] = 0;
    
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        
        if(dis[node] != INT_MAX) {
            for(auto next_node: adj[node]) {
                if(dis[next_node.first] > dis[node] + next_node.second)
                    dis[next_node.first] = dis[node] + next_node.seconnd;
            }
        }
    }
    
    for(int i = 0; i < V; i++)
        dis[i] == INT_MAX ? cout << "INF: " : cout << dis[i] << " ";
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<pair<int, int>> adj[V];
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // directed graph
        adj[u].push_back({v, w});
    }
    
    shortestPath(0, V, adj);
}
