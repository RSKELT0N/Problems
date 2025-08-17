#define BOTTOM_UP_TABULATION

class Solution {
public:
#ifdef BOTTOM_UP_TABULATION
    // Bottom up Tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if(obstacleGrid[0][0] == 1) return 0;
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();
        bool canReach = 1;

        for(int r = 1; r < m; r++) {
            if((obstacleGrid[r][0] == 0) && canReach) {
                obstacleGrid[r][0] = 1;
            } else {
                obstacleGrid[r][0] = 0;
                canReach = 0;
            }
        }

        canReach = 1;
        for(int c = 0; c < n; c++) {
            if((obstacleGrid[0][c] == 0) && canReach) {
                obstacleGrid[0][c] = 1;
            } else {
                obstacleGrid[0][c] = 0;
                canReach = 0;
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
#else
    // Top Down Memoization

    int solve(int r, int c, std::vector<std::vector<int>> & obstacleGrid)
    {
        if(r < 0 || c < 0) return 0;
        if(obstacleGrid[r][c] == -2) return 0;
        if(r == 0 && c == 0) return 1;
        if(obstacleGrid[r][c] != -1 && obstacleGrid[r][c] != -2) return obstacleGrid[r][c];

        obstacleGrid[r][c] = solve(r, c - 1, obstacleGrid) + solve(r - 1, c, obstacleGrid);
        return obstacleGrid[r][c];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();

        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = -2;
                else
                    obstacleGrid[i][j] = -1;
            }
        }
        return solve(m - 1, n - 1, obstacleGrid);
    }
#endif
};
