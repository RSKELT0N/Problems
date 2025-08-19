struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    std::unordered_map<std::pair<int, int>, int, pair_hash> dp;
    int solve(int startPos, int endPos, int k)
    {
        if(startPos == endPos && k == 0) return 1;
        if(std::abs(startPos - endPos) > k) return 0;
        if(dp.find({startPos, k}) != dp.end()) return dp[{startPos, k}];

        dp[{startPos, k}] = (solve(startPos + 1, endPos, k - 1) + solve(startPos - 1, endPos, k - 1)) % static_cast<int>(1e9 + 7);
        return dp[{startPos, k}];
    }

    int numberOfWays(int startPos, int endPos, int k) {
        return solve(startPos, endPos, k);
    }
};
