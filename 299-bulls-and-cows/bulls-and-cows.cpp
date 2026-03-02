class Solution {
public:
    string getHint(string secret, string guess){
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> count;
        for(char &x : secret){
            count[x]++;
        }
        for(int i = 0; i < guess.size(); i++){
            if(guess[i] == secret[i]){
                bulls++;
                count[secret[i]]--;
            }
        }
        for(int i = 0; i < guess.size(); i++){
            if(count[guess[i]] > 0 && guess[i] != secret[i]){
                cows++;
                count[guess[i]]--;
            }
        }
        string result = to_string(bulls) + "A" + to_string(cows) + "B";
        return result;
    }
};