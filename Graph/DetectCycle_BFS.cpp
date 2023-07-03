bool isCycleUtil(int start, vector<int> adj[], vector<int> &vis){
        queue<pair<int, int>> qu;
        
        qu.push({start, start});
        vis[start] = 1;
        
        while(!qu.empty()){
            auto node = qu.front();
            qu.pop();
            
            int prev_node = node.first;
            int curr_node = node.second;
            
            for(int next_node : adj[curr_node]){
                if(next_node != prev_node){
                    if(vis[next_node] == 1) return true;
                    qu.push({curr_node, next_node});
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(vis[i] == 0 && isCycleUtil(i, adj, vis))
                return true;
        }
        return false;
    } 