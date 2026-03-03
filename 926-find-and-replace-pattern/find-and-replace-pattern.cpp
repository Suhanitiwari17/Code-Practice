class Solution {
public:
    string normalPattern(const string& word){
        char curr_ch = 'a';
        string pattern = "";
        unordered_map<char, char> mp;
        for(const char& ch : word){
            if(mp.find(ch) != mp.end()){
                pattern.push_back(mp[ch]);
            }
            else{
                mp[ch] = curr_ch;
                pattern.push_back(curr_ch);
                curr_ch++;
            }
        }
        return pattern;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern){
        vector<string> result;
        string normal = normalPattern(pattern);
        for(const string& word : words){
            if(normalPattern(word) == normal){
                result.push_back(word);
            }
        }
        return result;
    }
};