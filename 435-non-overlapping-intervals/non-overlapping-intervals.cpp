class Solution {
    static bool comp(const vector<int> &a , const vector<int> &b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , comp);

        int n = intervals.size();
        int count=1;
        int lastCell = intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastCell){
                count++;
                lastCell = intervals[i][1];
            }
        }
        return n - count;
    }
};