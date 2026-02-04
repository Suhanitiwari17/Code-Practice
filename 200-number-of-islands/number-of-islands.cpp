class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& visited,vector<vector<char>> grid){
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delrow[4] ={-1,0,1,0};
            int delcol[4] ={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                    int nrow=row + delrow[i];
                    int ncol= col+delcol[i];

                    if(nrow >= 0 && nrow<n && ncol>= 0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol] =='1'){
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    count++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        return count;
    }
};