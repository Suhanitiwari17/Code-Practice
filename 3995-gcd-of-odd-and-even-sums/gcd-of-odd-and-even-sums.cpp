class Solution {
public:
        int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        int gcdOfOddEvenSums(int n) {
            int sumEven = 0 , sumOdd = 0;

            for(int i=1 ; i<=2*n ; i++){
                if(i%2 == 0) sumEven += i;
                else sumOdd += i;
            }

            int ans = gcd(sumOdd , sumEven);

            return ans;
        }
};