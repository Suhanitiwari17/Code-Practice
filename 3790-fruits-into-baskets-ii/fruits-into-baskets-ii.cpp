class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            bool placed = false;

            for(int j = 0; j < n; j++) {
                if(baskets[j] >= fruits[i]) {
                    baskets[j] = -1;
                    placed = true;
                    break;
                }
            }

            if(!placed) {
                ans++;
            }
        }

        return ans;
    }
};