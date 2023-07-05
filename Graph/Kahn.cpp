	vector<int> kahn(int V, vector<int> adj[]){
	    queue<int> qu;
	    vector<int> res;
	    vector<int> deg(V, 0);
	    
	    for(int i=0; i<V; i++){
	        for(int node : adj[i]){
	            deg[node]++;
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        if(deg[i] == 0){
	            qu.push(i);
	        }
	    }
	    
	    while(!qu.empty()){
	        int node = qu.front();
	        qu.pop();
	        
	        res.push_back(node);
	        
	        for(int next_node : adj[node]){
	            deg[next_node]--;
	            if(deg[next_node] == 0){
	                qu.push(next_node);
	            }
	        }
	    }
	    
	    return res;
	}