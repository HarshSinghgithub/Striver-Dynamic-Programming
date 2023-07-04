    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        queue<int> qu;
        vector<bool> vis(V, false);
        
        qu.push(0);
        
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
                
            
            res.push_back(node);
                
            for(int it : adj[node]){
                if(!vis[it]){
                    qu.push(it);
                }
            }
        }
        
        return res;
    }