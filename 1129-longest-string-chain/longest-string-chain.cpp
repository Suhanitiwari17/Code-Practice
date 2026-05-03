class Solution {
public:

    static bool comp (string& a,string& b){
        return a.length() < b.length();
    };

    bool isValid(string &s1 , string &s2){
        if(s1.length() != s2.length()+1) return false;

        int i=0,j=0;

        while(i<s1.length() && j<s2.length()){
            if(s1[i] == s2[j]){
                j++;
            }
            i++;
        }

        return j == s2.length();
    }
    
    int t[1001][1001];
    int solve(vector<string>& words,int i,int prev){
       if (i >= words.size()) return 0;

       int take=0;

       if(prev != -1 && t[i][prev] != -1) return t[i][prev];
       
       if( prev == -1 || 
       ( words[i].length() == words[prev].length() + 1 && isValid(words[i], words[prev]) )  ){
            take = 1 + solve(words , i+1 , i);
       }

       int skip = solve(words , i+1 , prev);

       if(prev!=-1) t[i][prev] = max(take , skip);

       return max(take , skip);
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , comp);

        memset(t,-1,sizeof(t));

        int n = words.size();

        return solve(words , 0 , -1);
    }
};