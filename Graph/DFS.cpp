void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &res){
        if(node == vis.size()) return;
        
        res.push_back(node);
        
        for(int it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                dfs(it, adj, vis, res);
            }
        }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        queue<int> qu;
        vector<int> vis(V, false);
        vis[0] = true;
        
        dfs(0, adj, vis, res);
        
        return res;
    }