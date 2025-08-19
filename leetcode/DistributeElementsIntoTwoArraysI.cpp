class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        std::vector<int> l, r;

        l.push_back(nums[0]);
        r.push_back(nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            if(l[l.size() - 1] > r[r.size() - 1])
                l.push_back(nums[i]);
            else
                r.push_back(nums[i]);
        }

        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};
