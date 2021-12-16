bool isCyclic(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& dfsVis) {
    vis[node] = true;
    dfsVis[node] = true;

    for(int next_node: adj[node]) {
        if(!vis[next_node]) {
            if(isCyclic(next_node, adj, vis, dfsVis)) return true;
        }
        else if(dfsVis[next_node]) return true;
    }

    dfsVis[node] = false;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A + 1);
    for(int i = 0; i < B.size(); i++)
        adj[B[i][0]].push_back(B[i][1]);

    vector<bool> vis(A + 1);
    vector<bool> dfsVis(A + 1);

    for(int i = 1; i <= A; i++) {
        if(!vis[i]) {
            if(isCyclic(i, adj, vis, dfsVis)) return 1;
        }
    }

    return 0;
}
