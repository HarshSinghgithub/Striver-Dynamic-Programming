class Solution {
public:

    bool detectCycle(int node, vector<int> &order, vector<int> adj[], vector<int> &vis, vector<int> &path){
        vis[node] = 1;
        path[node] = 1;

        for(int next_node : adj[node]){
            if(vis[next_node] == 0){
                if(detectCycle(next_node, order, adj, vis, path)){
                    return true;
                }
            }
            if(path[next_node] == 1)
                return true;
        }

        order.push_back(node);

        path[node] = 0;

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        vector<int> order;
        vector<int> adj[numCourses];

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(vis[i] == 0 && detectCycle(i, order, adj, vis, path)){
                return {};
            }
        }

        reverse(order.begin(), order.end());

        return order;
    }
};