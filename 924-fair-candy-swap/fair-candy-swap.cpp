class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumA - sumB) / 2;
        
        unordered_set<int> setB(B.begin(), B.end());
        for(int x : A) {
            int y = x - delta;
            if(setB.count(y)) return {x, y};
        }
        return {};
    }
};