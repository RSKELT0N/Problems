/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    // Recursion Solution
    // Recursive Top Down Memoization Approach
    // int maxProfit(vector<int>& prices)
    // {
    //     std::ios_base::sync_with_stdio(false);
    //     std::cout.tie(0);
    //     std::cin.tie(0);

    //     int n = prices.size();

    //     int dp[n + 1][2];
    //     memset(dp, -1, sizeof(dp));

    //     std::function<int(int, int)> func = [&](int i, int b)
    //     {
    //         if(i == n) return 0;
    //         if(dp[i][b] != -1) return dp[i][b];

    //         int max = 0;

    //         if(b == 1)
    //             max = std::max(max, prices[i] + func(i + 1, b + 1));
    //         else if(b == 0)
    //             max = std::max(max, -prices[i] + func(i, b + 1));

    //         max = std::max(max, func(i + 1, b));
    //         return dp[i][b] = max;
    //     };

    //     return func(0, 0);
    // }

    // Iterative Bottom-up Tabulation Approach
    int maxProfit(vector<int>& prices)
    {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(0);
        std::cin.tie(0);

        int n = prices.size();

        int dp[n + 1][3];
        memset(dp, -1, sizeof(dp));

        for(int i = n; i >= 0; i--)
        {
            for(int b = 2; b >= 0; b--)
            {
                if(i == n)
                {
                    dp[i][b] = 0;
                    continue;
                }

                if(dp[i][b] != -1) continue;

                int max = 0;

                if(b == 1) max = std::max(max, prices[i] + dp[i + 1][b + 1]);
                if(b == 0) max = std::max(max, -prices[i] + dp[i][b + 1]);

                max = std::max(max, dp[i + 1][b]);
                dp[i][b] = max;
            }
        }

        return dp[0][0];
    }
};
