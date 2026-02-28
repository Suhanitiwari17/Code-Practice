class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        if(rows == 0) return 0;
        int cols = heightMap[0].size();
        if(cols == 0) return 0;

        vector<vector<int>> seen(rows, vector<int>(cols, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int r = 0; r < rows; r++){
            pq.push({heightMap[r][0], r, 0});
            pq.push({heightMap[r][cols - 1], r, cols - 1});
            seen[r][0] = 1;
            seen[r][cols - 1] = 1;
        }

        for(int c = 1; c < cols; c++){
            pq.push({heightMap[0][c], 0, c});
            pq.push({heightMap[rows - 1][c], rows - 1, c});
            seen[0][c] = 1;
            seen[rows - 1][c] = 1;
        }

        int total = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            int level = cur[0];
            int r = cur[1];
            int c = cur[2];

            for(auto& d : dirs){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || seen[nr][nc]) continue;

                seen[nr][nc] = 1;

                int nextHeight = heightMap[nr][nc];
                if(nextHeight < level){
                    total += level - nextHeight;
                    pq.push({level, nr, nc});
                }else{
                    pq.push({nextHeight, nr, nc});
                }
            }
        }

        return total;
    }
};