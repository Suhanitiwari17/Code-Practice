class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower;
        unordered_set<char> upper;

        for(int i=0;i<word.length();i++){
            if(islower(word[i])){
                lower.insert(word[i]);
            }
            else{
                upper.insert(tolower(word[i]));
            }
        }

        int c=0;
        for(char ch : lower){
            if(upper.count(ch)) c++;

        }
        return c;
    }
};