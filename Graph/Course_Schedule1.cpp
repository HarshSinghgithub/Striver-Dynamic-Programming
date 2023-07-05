class Solution {
public:

    bool detectCycle(int n, vector<int> adj[], vector<int> &deg){
        queue<int> qu;
        vector<int> res;

        for(int i=0; i<n; i++){
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
                if(deg[next_node] == 0) qu.push(next_node);
            }
        }

        return (n == res.size());       
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> deg(numCourses, 0);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<numCourses; i++){
            for(int node : adj[i]){
                deg[node]++;
            }
        }

        return detectCycle(numCourses, adj, deg);
    }
};