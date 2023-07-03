bool isCycleUtil(int prev_node, int curr_node, vector<int> adj[], vector<int> &vis){
        vis[curr_node] = 1;
        
        for(int next_node : adj[curr_node]){
            if(next_node != prev_node){
                if(vis[next_node] == 1) return true;
                if(isCycleUtil(curr_node, next_node, adj, vis))
                    return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(vis[i] == 0 && isCycleUtil(i, i, adj, vis))
                return true;
        }
        return false;
    }