#define BOTTOM_UP_TABULATION

class Solution {
public:
#ifdef BOTTOM_UP_TABULATION
    // Bottom Up Tabulation
    std::vector<std::vector<int>> dp;
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        dp = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for(int i = 1; i < m; i++)
            dp[i][0] = grid[i][0] + dp[i - 1][0];

        for(int i = 1; i < n; i++)
            dp[0][i] = grid[0][i] + dp[0][i - 1];

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n ; j++) {
                dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
#else
    // Top Down Memoization
    std::vector<std::vector<int>> mem;
    int solve(int r, int c, std::vector<std::vector<int>> & grid)
    {
        if(r < 0 || c < 0) return INT_MAX;
        if(r == 0 && c == 0) return grid[r][c];
        if(mem[r][c] != -1) return mem[r][c];

        mem[r][c] = grid[r][c] + std::min(solve(r - 1, c, grid), solve(r, c - 1, grid));
        return mem[r][c];
    }

    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        mem = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));

        return solve(m - 1, n - 1, grid);
    }
#endif
};
