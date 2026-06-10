class Solution {
public:
    bool consecutiveSetBits(int n) {
        vector<int> ans;

        if(n==0) return false;
        
        while(n!=0){
            int r = n%2;
            ans.push_back(r);

            n=n/2;
        }

        int count = 0;

        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==1 && ans[i+1]==1) count++;
        }

        if(count==1){
            return true;
        }

        return false;
    }
};