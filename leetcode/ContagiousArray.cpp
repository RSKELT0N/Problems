class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count = 0;
        int total = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                count++;
            else count--;
        if (mp.find(count) != mp.end()) {
                total = max(total, i - mp[count]);
            } else {
                mp[count] = i;
            }
        }
        return total;
    }
};
