class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int start=1,end=(position[n-1]-position[0]),ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(position,m,mid)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    bool isPossible(vector<int>& position, int m,int minAllowedDist){
        //sort(position.begin(),position.end());
        int ball=1,lastpos=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-lastpos>=minAllowedDist){
                ball++;
                lastpos=position[i];
            }
        }
        if(ball>=m){
            return true;
        }else{
            return false;
        }
    }
};