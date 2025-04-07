class Solution {
    public int removeDuplicates(int[] nums) {
        int t=nums[0];
        int index=1;
        nums[0]=t;
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=t){
                nums[index]=nums[i];
                index++;
                t=nums[i];
            }
        }
        return index;
        
    }
}