class Solution {
public:

    bool bfs(int start, vector<int> adj[], vector<int> &color){
        queue<int> qu;
        qu.push(start);
        
        color[start] = 0;
        
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            
            for(int next_node : adj[node]){
                if(color[next_node] == -1){
                    color[next_node] = !color[node];
                    qu.push(next_node);
                }
                if(color[next_node] != -1 && color[node] == color[next_node]){
                    return false;
                }
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    
	    for(int i=0; i<V; i++){
	        if(color[i] == -1 && bfs(i, adj, color) == false){
	            return false;
	        }
	    }
	    
	    return true;
	}

};