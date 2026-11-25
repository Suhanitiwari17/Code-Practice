class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
       
        unordered_set<int> resSet;
        


        for(int num : nums2) {
            if(s1.count(num)) {
                resSet.insert(num);
            }
        }
        return vector<int>(resSet.begin(), resSet.end());
    }
};