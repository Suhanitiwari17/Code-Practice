class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int amt;
        sort(prices.begin() , prices.end());

        for(int i=0 ; i<prices.size()-1 ; i++){
            for(int j=i+1 ; j<prices.size() ; j++){
                if(prices[i] + prices[j] <= money){
                    amt = money - (prices[i] + prices[j]);
                    return amt;
                }
            }
        }
        return money;
    }
};