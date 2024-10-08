/*
188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

// Top Down Memoization
// class Solution {
// public:
//     int maxProfit(int k, std::vector<int>& prices)
//     {
//         std::ios_base::sync_with_stdio(false);
//         std::cout.tie(0);
//         std::cin.tie(0);

//         int n = prices.size();

//         int dp[n + 1][k + 1][2];
//         memset(dp, -1, sizeof(dp));

//         std::function<int(int, int, int)> solve = [&](int idx, int k, int bought)
//         {
//             if (idx == n) return 0;
//             if (dp[idx][k][bought] != -1) return dp[idx][k][bought];

//             int profit = 0;

//             if (bought)
//                 profit = std::max(profit, prices[idx] + solve(idx + 1, k, 0));
            
//             if (k > 0 && !bought)
//                 profit = std::max(profit, -prices[idx] + solve(idx + 1, k - 1, 1));
            
//             profit = std::max(profit, solve(idx + 1, k, bought));
//             return dp[idx][k][bought] = profit;
//         };

//         return solve(0, k, 0);
//     }
// };

// Bottom Up Tabulation
class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices)
    {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(0);
        std::cin.tie(0);

        int n = prices.size();

        int dp[n + 1][k + 1][2];
        memset(dp, -1, sizeof(dp));

        for(int idx = n; idx >= 0; idx--)
        {
            for(int k_rem = 0; k_rem <= k; k_rem++)
            {
                for(int bought = 0; bought <= 1; bought++)
                {
                    if (idx == n)
                    {
                        dp[idx][k_rem][bought] = 0;
                        continue;
                    }

                    if (dp[idx][k_rem][bought] != -1) continue;

                    int profit = 0;

                    if (bought) profit = std::max(profit, prices[idx] + dp[idx + 1][k_rem][0]);

                    if (k_rem > 0 && !bought) profit = std::max(profit, -prices[idx] + dp[idx + 1][k_rem - 1][1]);
                    
                    profit = std::max(profit, dp[idx + 1][k_rem][bought]);
                    dp[idx][k_rem][bought] = profit;
                }
            }
        }

        return dp[0][k][0];
    }
};
