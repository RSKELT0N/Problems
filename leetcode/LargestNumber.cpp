class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
            std::string A = std::to_string(a);
            std::string B = std::to_string(b);
            return A + B > B + A;
        });

        if(nums[0] == 0)
            return "0";

        std::string ret = "";
        for(auto x : nums) {
            ret += std::to_string(x);
        }

        return ret;
    }
};
