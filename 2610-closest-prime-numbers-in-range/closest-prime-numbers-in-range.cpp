class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= right; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i)
                    isPrime[j] = false;
            }
        }
        
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }
        
        if (primes.size() < 2)
            return {-1, -1};
    
        int bestDiff = INT_MAX;
        vector<int> answer = {-1, -1};
        for (int i = 1; i < (int)primes.size(); ++i) {
            int diff = primes[i] - primes[i - 1];
            if (diff < bestDiff) {
                bestDiff = diff;
                answer = {primes[i - 1], primes[i]};
            }
        }
        
        return answer;
    }
};
