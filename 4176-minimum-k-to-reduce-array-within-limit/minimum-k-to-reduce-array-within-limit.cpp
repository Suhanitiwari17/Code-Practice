class Solution {
public:
    
    int minimumK(vector<int>& nums) {
        int l =1;
        int r = 200000;
        int res = r;
        while(l <= r){
            int mid = l+(r-l)/2;
            long long op = 0;
            for(int i : nums){
                op = op+(i+mid-1)/mid;
                if(op>1LL*mid*mid){
                    break;
                }
            }
            if(op<=1LL*mid*mid){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};