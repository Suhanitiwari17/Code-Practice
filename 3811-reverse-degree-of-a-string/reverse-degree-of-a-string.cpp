class Solution {
public:
    int reverseDegree(string s) {
        
        //int pro = 1;
        int sum = 0;
        for(int i=1 ; i<=s.size() ; i++){
            int rev = 'z' - s[i-1] + 1;
            int pro = rev * i;

            sum += pro;
        }
        return sum;
    }
};