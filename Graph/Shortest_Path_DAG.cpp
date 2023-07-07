void topoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int next_node = it.first;
            if(!vis[next_node]){
                topoSort(next_node, vis, st, adj);
            }
        }
        
        st.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        vector<int> vis(N, 0);
        vector<int> dist(N, 1e9);
        stack<int> st;
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            
            adj[u].push_back({v, cost});
        }
        
        for(int i=0; i<N; i++){
            if(vis[i] == 0){
                topoSort(i, vis, st, adj);
            }
        }
        
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int next_node = it.first;
                int cost = it.second;
                
                if(dist[node] + cost < dist[next_node]){
                    dist[next_node] = dist[node] + cost;
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }