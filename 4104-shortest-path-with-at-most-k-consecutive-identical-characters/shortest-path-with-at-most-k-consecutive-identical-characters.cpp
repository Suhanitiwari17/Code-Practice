class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        if (k < 1) return -1;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, node, count] = pq.top();
            pq.pop();

            if (cost != dist[node][count]) continue;

            if (node == n - 1) return cost;

            for (auto [next, weight] : adj[node]) {
                int newCount = (labels[node] == labels[next]) ? count + 1 : 1;

                if (newCount > k) continue;

                long long newCost = cost + weight;

                if (newCost < dist[next][newCount]) {
                    dist[next][newCount] = newCost;
                    pq.push({newCost, next, newCount});
                }
            }
        }

        return -1;
    }
};