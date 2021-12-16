  void topoSortUtil(int node, vector<bool>& vis, stack<int>& st, vector<int> adj[]) {
	    vis[node] = true;
	    
	    for(int next_node: adj[node]) {
	        if(!vis[next_node])
	            topoSortUtil(next_node, vis, st, adj);
	    }
	    st.push(node);
	}

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<bool> vis(V + 1, false);
	    
	    for(int i = 0; i < V; i++) {
	        if(!vis[i])
	            topoSortUtil(i, vis, st, adj);
	    }
	    
	    vector<int> ans;
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
