class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());

        long long sum=0,count=0;

        for(int i=0 ; i<costs.size() ; i++){
            if(costs[i] > coins) continue;
            sum += costs[i];
            if(sum <= coins) count++;
            if(sum == coins) break;
            
        }

        return count;
    }
};