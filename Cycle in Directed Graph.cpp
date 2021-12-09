bool dfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
    vis[start] = 1;

    for(int next_node: adj[start]) {
        if(vis[next_node] == 0)
            if(dfs(next_node, adj, vis))
                return true;
        else if(vis[next_node] == 1)
            return true;
    }
    vis[start] = 2;

    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A + 1);
    for(int i = 0; i < B.size(); i++) {
        // directed graph
        adj[B[i][0]].push_back(B[i][1]);
    }

    vector<int> vis(A + 1, 0);
    for(int i = 1; i <= A; i++) {
        if(!vis[i])
            if(dfs(i, adj, vis))
                return 1;
    }
    return 0;
}
