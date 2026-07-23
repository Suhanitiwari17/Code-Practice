class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2) return n;
        else{
            int i = 1;
            while(i <= n){
                i *= 2;
            }
            return i;
        }
    }
};