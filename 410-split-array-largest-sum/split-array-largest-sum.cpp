class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int end=sum,ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
    bool isValid(vector<int>& nums, int k,int maxAllowedPages){
        int arr=1,digits=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxAllowedPages){
                return false;
            }
            if(digits+nums[i]<=maxAllowedPages){
                digits+=nums[i];
            }else{
                arr++;
                digits=nums[i];
            }
        }
        if(arr>k){
            return false;
        }else{
            return true;
        }
    }
    
};