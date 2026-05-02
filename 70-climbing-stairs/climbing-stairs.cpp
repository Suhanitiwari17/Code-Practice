class Solution {
public:
    //nt count;
    int t[46];
    int solve(int n,int idx){
        
        if(n<0) return 0;

        if(n==0) return 1;

        if(t[idx] != -1) return t[idx];

        int one_step = solve(n-1,idx+1);

        int two_step = solve(n-2,idx+2);

        return t[idx] = one_step + two_step;
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));

        return solve(n,0);
    }
};