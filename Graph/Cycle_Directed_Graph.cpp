bool dfs(int node, vector<int> &path, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        path[node] = 1;
        
        for(int next_node : adj[node]){
            if(path[next_node] == 1) return true;
            if(vis[next_node] == 0 && dfs(next_node, path, vis, adj)) return true;
        }
        
        path[node] = 0;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> path(V, 0);
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(vis[i] == 0 && dfs(i, path, vis, adj)){
                return true;
            }
        }
        
        return false;
    }