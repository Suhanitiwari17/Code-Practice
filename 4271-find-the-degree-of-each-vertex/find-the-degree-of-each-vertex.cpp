class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> adj(n);


        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> result;

        for(int i=0 ; i<n ; i++){
            int count = 0;
            for(int node : adj[i]){
                count++;
            }
            result.push_back(count);
        }

        return result;
    }
};