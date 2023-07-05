class Solution
{
	public:
	//Function to return list containing vertices in Topological orde
	
	void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
	    vis[node] = 1;
	    
	    for(int next_node : adj[node]){
	        if(vis[next_node] == 0){
	            dfs(next_node, adj, vis, st);
	        }
	    }
	    
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0);
	    stack<int> st;
	    vector<int> res;
	    
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i, adj, vis, st);
	        }
	    }
	    
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	    return res;
	}
};