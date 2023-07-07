    void topo_sort(int node, vector<int> &vis, vector<int> &res, vector<int> adj[]){
        vis[node] = 1;
        
        for(int next_node : adj[node]){
            if(vis[next_node] == 0){
                topo_sort(next_node, vis, res, adj);
            }
        }
        
        res.push_back(node);
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        vector<int> ds;
        vector<int> vis(K, 0);
        string res = "";
        
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.length(), s2.length());
            
            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
            
        }
        
        for(int i=0; i<K; i++){
            if(vis[i] == 0){
                topo_sort(i, vis, ds, adj);
            }
        }
        
        reverse(ds.begin(), ds.end());
        
        for(int i=0; i<ds.size(); i++){
            char ch = ds[i] + 97;
            res = res + ch;
        }
        
        return res;
    }