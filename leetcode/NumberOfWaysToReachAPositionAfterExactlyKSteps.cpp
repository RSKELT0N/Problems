class Solution {
public:
    std::vector<std::vector<int>> dp;
    int solve(int startPos, int endPos, int k)
    {
        if(startPos == endPos && k == 0) return 1;
        if(std::abs(startPos - endPos) > k) return 0;
        if(dp[std::abs(startPos - endPos)][k] != -1) return dp[std::abs(startPos - endPos)][k];

        dp[std::abs(startPos - endPos)][k] = (solve(startPos + 1, endPos, k - 1) + solve(startPos - 1, endPos, k - 1)) % static_cast<int>(1e9 + 7);
        return dp[std::abs(startPos - endPos)][k];
    }

    int numberOfWays(int startPos, int endPos, int k) {
        dp = std::vector<std::vector<int>>(k + 1, std::vector<int>(k + 1, -1));
        return solve(startPos, endPos, k);
    }
};
