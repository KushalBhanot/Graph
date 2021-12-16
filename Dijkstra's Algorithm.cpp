// it works only when there is no negative edge in a graph
// it is efficient for larger graphs since it always processes an edge once
// it is a greedy algorithm which uses a min priority queue

vector <int> dijkstra(int V, vector<pair<int, int>> adj[], int S) {
    // min priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
        
    vector<int> dis(V + 1, INT_MAX);
    dis[S] = 0;
        
    while(!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.top();
            
        int w = node.first;
        int u = node.second;
            
        if(w > dis[u]) continue;
        for(pair<int, int> v: adj[u]) {
            if(dis[v.first] > dis[u] + v.second) {
                dis[v.first] = dis[u] + v.second;
                pq.push({dis[v.first], v.first});
            }
        }
    }
    return dis;
}
