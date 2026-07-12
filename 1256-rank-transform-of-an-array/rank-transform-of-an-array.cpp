class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         vector<int> copy = arr;

         sort(copy.begin() , copy.end());

         unordered_map<int,int> mp;
         int rank = 1;

         for(int i : copy){
            if(!mp.count(i)){
                mp[i] = rank++;
            }
         }

         for(int &it : arr){
            it = mp[it];
         }

         return arr;



        }
    
};