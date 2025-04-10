class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;

        // Reverse only half of the number to avoid overflow
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }

        // For even length: x == reversed
        // For odd length: x == reversed / 10
        return x == reversed || x == reversed / 10;
    }
        
        
 }
