class Solution {
public:
    int t[501][501];
    int solve(string& word1,string& word2,int i,int j){
        int m = word1.length();
        int n = word2.length();

        if(i == word1.length()) return n-j;

        else if(j == word2.length()) return m-i;

        if(t[i][j] != -1) return t[i][j];


        if(word1[i] == word2[j]){
            return solve(word1 , word2 , i+1 , j+1);
        }
        else{
            int insert = 1 + solve(word1 , word2 , i , j+1);
            int del = 1 + solve(word1 , word2 , i+1 , j);
            int replace = 1 + solve(word1 , word2 , i+1 , j+1);

            return t[i][j] = min({insert , del , replace});
        }

        return -1;
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));

        return solve(word1 , word2 , 0 , 0);
    }
};