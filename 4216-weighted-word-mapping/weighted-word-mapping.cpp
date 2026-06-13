class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string finalString = "";

        for(auto &i : words){
            int sum=0;

            for(char c : i){
                sum += weights[c - 'a'];
            }

            int ans = sum%26;
            char mapp ='z'-ans;
            finalString.push_back(mapp);
        }
        return finalString;
    }
};