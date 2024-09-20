
class Solution {
public:
    // Recursion Solution

    // int maxProfit(vector<int>& prices)
    // {
    //     std::function<int(int,int,bool)> func = [&](int i, int p, bool b)
    //     {
    //         if(i >= prices.size())
    //             return 0;

    //         int max = prices[i] - prices[p];

    //         if(b == false)
    //             max = std::max(max, func(i + 1, i, false));
            
    //         if(b == false)
    //             max = std::max(max, func(i, p, true));

    //         return dp[i][p] = std::max(max, func(i + 1, p, b));
    //     };

    //     return func(1, 0, false);
    // }

    // Iterative Bottom-up Tabulation Approach

    int maxProfit(vector<int>& prices)
    {
        short dp[prices.size() + 1][prices.size() + 1][2];
        memset(dp, -1, sizeof(dp));

        for(int i = prices.size() - 1; i >= 0; i--)
        {
            for(int p = 0; p < prices.size(); p++)
            {
                for(int b = 0; b < 2; b++)
                {
                    if(i >= prices.size())
                    {
                        dp[i][p][b] = 0;
                        continue;
                    }

                    short max = static_cast<short>(prices[i] - prices[p]);

                    if(b == false)
                        max = std::max(max, dp[i + 1][i][false]);
                    
                    if(b == false)
                        max = std::max(max, dp[i][p][true]);

                    dp[i][p][b] = std::max(max, dp[i + 1][p][b]);
                }
            }
        }

        return static_cast<int>(dp[0][0][false]);
    }
};
