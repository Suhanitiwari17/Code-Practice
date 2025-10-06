class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int width=right-left;
            int ht=min(height[left],height[right]);
            int currentwater=ht * width;
            maxwater=max(maxwater,currentwater);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxwater;
    }
};