class Solution {
public:
    bool isPalindrome(string s) {
        int start=0,end=s.length();
        while(start<end){
            if(!isAlphanumeric(s[start])){
                start++;
                continue;
            }
            if(!isAlphanumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            start++,end--;
        }
        return true;
        
    }
    bool isAlphanumeric(char ch){
        if(ch>='0'&&ch<='9' || tolower(ch)>='a' && tolower(ch)<='z'){
            return true;
        }
        return false;
    }
};