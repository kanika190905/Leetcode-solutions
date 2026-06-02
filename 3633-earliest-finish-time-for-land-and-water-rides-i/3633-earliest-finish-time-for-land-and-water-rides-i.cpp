class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {

                // Land -> Water
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);
                ans = min(ans, waterStart + waterDuration[j]);

                // Water -> Land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterFinish, landStartTime[i]);
                ans = min(ans, landStart + landDuration[i]);
            }
        }

        return ans;
    }
};