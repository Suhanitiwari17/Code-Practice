class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>> adj(v);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        

        vector<int> indegree(v,0);

        for(int i=0 ; i<v ; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0 ; i<v ; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == v) return topo;
        return {};
    }
};