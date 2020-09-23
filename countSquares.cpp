class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int dp[matrix.size()][matrix[0].size()];
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                dp[0][j] = matrix[0][j];
                dp[i][0] = matrix[i][0];
            } 
        }
        
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                int val = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                if(dp[i-1][j-1] == dp[i-1][j] && dp[i-1][j-1] == dp[i][j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = val+1;
                // if(i == 2 && j == 2) {
                //     cout << dp[i][j] << endl;
                //     cout << matrix[i][j] << endl;
                //     cout << val << endl;
                // }
            
            }
        }
        int count = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(dp[i][j] != 0)
                    count += dp[i][j];
            }
        }
        return count;
    }
};
