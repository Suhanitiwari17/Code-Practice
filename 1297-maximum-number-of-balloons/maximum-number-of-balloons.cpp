class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char , int> mp;

        for(char c : text){
            mp[c]++;
        }

         return min({
            mp['b'],
            mp['a'],
            mp['n'],
            mp['l'] / 2,
            mp['o'] / 2
        });
    }
};