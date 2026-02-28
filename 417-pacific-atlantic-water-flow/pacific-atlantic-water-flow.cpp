class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;

        for(int r = 0; r < rows; r++){
            q1.push({r, 0});
            q2.push({r, cols - 1});
            pacific[r][0] = 1;
            atlantic[r][cols-1] = 1;
        }

        for(int c = 0; c < cols; c++){
            q1.push({0, c});
            q2.push({rows - 1, c});
            pacific[0][c] = 1;
            atlantic[rows - 1][c] = 1;
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q1.empty()){
            auto cur = q1.front();
            q1.pop();

            int r = cur.first;
            int c = cur.second;

            for(auto& d : dirs){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if(pacific[nr][nc]) continue;
                if(heights[nr][nc] < heights[r][c]) continue;

                pacific[nr][nc] = 1;
                q1.push({nr, nc});
            }
        }

        while(!q2.empty()){
            auto cur = q2.front();
            q2.pop();

            int r = cur.first;
            int c = cur.second;

            for(auto& d : dirs){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if(atlantic[nr][nc]) continue;
                if(heights[nr][nc] < heights[r][c]) continue;

                atlantic[nr][nc] = 1;
                q2.push({nr, nc});
            }
        }
        vector<vector<int>> ans;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};