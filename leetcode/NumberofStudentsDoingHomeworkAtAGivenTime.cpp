class Solution {
public:
    int ans = 0;
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        for(int i = 0; i < startTime.size(); i++) {
            if(queryTime >= startTime[i] && queryTime <= endTime[i])
                ans++;
        }
        return ans;
    }
};
