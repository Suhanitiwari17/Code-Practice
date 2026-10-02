class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n+1 , 0);
        vector<int> trusting(n+1 , 0);

        for(vector<int>& curr : trust){
            int trustedPerson = curr[1];
            int trustingPerson = curr[0];

            trusted[trustedPerson]++;
            trusting[trustingPerson]++;
        }

        for(int i=1 ; i<=n ; i++){
            if(trusted[i] == n-1 && trusting[i] == 0) return i;
        }
        return -1;
    }
};