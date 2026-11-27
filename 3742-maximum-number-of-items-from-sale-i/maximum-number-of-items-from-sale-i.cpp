class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        
        vector<int> count(1501,0);
        
        for(auto &x : items){
            count[x[0]]++;
        }
        vector<int> profit(n,1);

        for(int i=0;i<n;i++){
            int a = items[i][0];

            int free = 0;

            for(int j = a ; j<=1500;j+=a){
                free += count[j];
            }
            free--;
            profit[i]=1+free;
            
        }
        vector<int> dp(budget+1,0);

        for(int i =0;i<n;i++){
            int c = items[i][1];
            int v = profit[i];

            for(int j = budget;j>=c;j--){
                dp[j]=max(dp[j],dp[j-c]+v);
            }
        }
        int res=0;
        for(int k=1;k<=1500;k++){
            bool flag = false;
            for(auto &it:items){
                if(it[1] == k){
                    flag = true;
                    break;
                }
            }
            if(!flag) continue;

            for(int l =0;l<=budget;l++){
                res = max(res , dp[l]+(budget-l)/k);
            }
        }
        return res;
    }
};