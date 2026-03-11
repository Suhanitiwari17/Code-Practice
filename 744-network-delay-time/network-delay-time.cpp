class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});

        vector<int> dist(n+1,1e9);

        dist[k]=0;

        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;

            pq.pop();

            for(auto it:adj[node]){
                int edgeWt=it.second;
                int adjNode=it.first;
                if(distance + edgeWt < dist[adjNode]){
                    dist[adjNode]=distance + edgeWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        int maxi=0;

        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            maxi=max(maxi,dist[i]);
        }

        return maxi;


    }
};