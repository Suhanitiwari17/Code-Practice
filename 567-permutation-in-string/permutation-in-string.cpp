class Solution {
public:
    bool isFreqSame(int freq1[],int freq2[]){
       for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]) return false;
       }
       return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.length();i++){
            int idx=s1[i]-'a';
            freq[idx]++;
        }
        int windSize=s1.length();
        for(int i=0;i<s2.length();i++){
            int winIdx=0,idx=i;
            int winFreq[26]={0};
            while(winIdx<windSize && idx<s2.length()){
                winFreq[(s2[idx]-'a')]++;
                winIdx++;
                idx++;
            }
            if(isFreqSame(freq,winFreq)){
                return true;
            }
        }
        return false;
    }
    
};