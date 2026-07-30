class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int totalPushes = 0;
        
        for (int i = 0; i < n; i++) {
            int pushesPerKey = (i / 8) + 1; 
            totalPushes += pushesPerKey;
        }
        
        return totalPushes;
    }
};
