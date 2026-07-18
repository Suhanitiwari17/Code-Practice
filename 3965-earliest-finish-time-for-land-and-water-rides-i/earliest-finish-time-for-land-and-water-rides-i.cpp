class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
         int mini = INT_MAX;

         for(int i = 0 ; i < landStartTime.size() ; i++){
            int end_time = landStartTime[i] + landDuration[i];

            for(int j = 0 ; j < waterDuration.size() ; j++){

                int water_Begin = max(end_time, waterStartTime[j]);

                mini = min (mini , water_Begin + waterDuration[j]);
            }
         }

         for(int i = 0 ; i < waterStartTime.size() ; i++){
            int end_time = waterStartTime[i] + waterDuration[i];

            for(int j = 0 ; j < landDuration.size() ; j++){
                
                int land_begin = max(end_time, landStartTime[j]);

                mini = min (mini , land_begin + landDuration[j]);
            }
         }

         return mini;
    }
};