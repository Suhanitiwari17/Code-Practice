class Solution {
    public void sortColors(int[] nums) {
        int c0=0,c1=0,c2=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c0+=1;
            }
            else if(nums[i]==1){
                c1+=1;
            }
            else{
                c2+=1;
            }
        }
        int index=0;
        for(int i=0;i<c0;i++){
            nums[index++]=0;
        }
        for(int i=0;i<c1;i++){
            nums[index++]=1;
        }
        for(int i=0;i<c2;i++){
            nums[index++]=2;
        }
    }
}