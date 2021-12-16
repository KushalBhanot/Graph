// shortest path in undirected graph with unit weights from sources to all the other vertices
void bfs(int N, vector<int> adj[], int src) {
    vector<int> dis(N + 1, INT_MAX);
    dis[src] = 0;
    
    queue<int> q;
    q.push(src);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int next_node: adj[node]) {
            if(dis[next_node] >  dis[node] + 1) {
                dis[next_node] = dis[node] + 1;
                q.push(next_node);
            }
        }
    }
    
    for(int i = 0; i < N; i++)
        cout << dis[i] << " ";
}
