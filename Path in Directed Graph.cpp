int dfs(int start, int end, vector<vector<int>>& adj, vector<bool>& vis) {
    if(start == end)
        return 1;

    vis[start] = true;
    for(int next_node: adj[start]) {
        if(!vis[next_node])
            dfs(next_node, end, adj, vis);
    }
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<bool> vis(A + 1, false);
    vector<vector<int>> adj(A + 1);
    // directed graph
    for(int i = 0; i < B.size(); i++)
        adj[B[i][0]].push_back(B[i][1]);

    return dfs(1, A, adj, vis);
}
