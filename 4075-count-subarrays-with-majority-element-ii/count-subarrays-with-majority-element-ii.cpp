class Solution {
public:
    class BIT {
    public:
        vector<int> bit;
        int n;

        BIT(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while(idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while(idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        bool found = false;
        for(int x : nums) {
            if(x == target) {
                found = true;
                break;
            }
        }

        if(!found) {
            return 0;
        }

        BIT bit(2 * n + 5);

        int pref = n + 2;
        bit.update(pref, 1);

        long long ans = 0;

        for(int x : nums) {
            if(x == target) {
                pref++;
            } else {
                pref--;
            }

            ans += bit.query(pref - 1);
            bit.update(pref, 1);
        }

        return ans;
    }
};