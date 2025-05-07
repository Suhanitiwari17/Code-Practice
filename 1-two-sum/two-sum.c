/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   
    int i,j;
    int *ans=(int *)malloc(sizeof(int*)*2);
    for(i=0;i<numsSize;i++)
    {
       int a= nums[i];
       for(j=i+1;j<numsSize;j++)
       {
           if(a+nums[j]==target)
           {
               ans[0]=i;
               ans[1]=j;
               *returnSize = 2; 
               return(ans);
           }
       }
    }
    return 0;
}

