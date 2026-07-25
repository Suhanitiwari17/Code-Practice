class Solution {
public:
    int maxProduct(int n) {
         vector<int> arr;

        while (n > 0) {
            arr.push_back(n % 10);
            n /= 10;
        }

        int maxi = 0;

        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
               int  pro = arr[i]*arr[j];
                maxi = max(pro,maxi);
            }
        }
        return maxi;
    }
};