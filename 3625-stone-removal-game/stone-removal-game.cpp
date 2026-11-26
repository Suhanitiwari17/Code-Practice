class Solution {
public:
    bool canAliceWin(int n) {
       int stone = n;
       int count = 10;
       int winnerAlice = true;

       while(stone >= count){
         stone -= count;
         count--;
         winnerAlice = !winnerAlice;
       }

    return !winnerAlice;
    }
};