    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        vector<int> vis(N, 0);
        vector<int> dist(N, 1e9);
        queue<pair<int, int>> qu;
        qu.push({src, 0});
        dist[src] = 0;
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();
            
            int node = it.first;
            int curr_dist = it.second;
            
            for(int next_node : adj[node]){
                if(dist[next_node] > curr_dist + 1){
                    dist[next_node] = curr_dist + 1;
                    qu.push({next_node, curr_dist + 1});
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