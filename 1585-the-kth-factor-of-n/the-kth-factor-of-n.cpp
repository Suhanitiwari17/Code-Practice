#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> small, large;
        for(int i = 1; i * 1LL * i <= n; i++) {
            if(n % i == 0) {
                small.push_back(i);
                if(i != n / i) large.push_back(n / i);
            }
        }
        reverse(large.begin(), large.end());
        small.insert(small.end(), large.begin(), large.end());

        if(k <= small.size()) return small[k-1];
        return -1;
    }
};
