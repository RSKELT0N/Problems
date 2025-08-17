#define BOTTOM_UP_TABULATION

class Solution {
public:

#ifdef BOTTOM_UP_TABULATION
    // Bottom up tabulation
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> cache(m, std::vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            cache[i][0] = 1;

        for(int i = 0; i < n; i++)
            cache[0][i] = 1;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                cache[i][j] = cache[i][j - 1] + cache[i - 1][j];
            }
        }

        return cache[m - 1][n - 1];
    }

#else
    // Top Down Memoization
    int solve(int r, int c, std::vector<std::vector<int>> & cache)
    {
        if(r < 0 || c < 0) return 0;
        if(r == 0 && c == 0) return 1;
        if(cache[r][c] != -1) return cache[r][c];

        cache[r][c] = solve(r, c - 1, cache) + solve(r - 1, c, cache);
        return cache[r][c];
    }

    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> cache;
        for(int i = 0; i < m; i++) {
            cache.push_back({});
            for(int j = 0; j < n; j++) {
                cache[i].push_back(-1);
            }
        }

        return solve(m - 1, n - 1, cache);
    }
#endif
};
