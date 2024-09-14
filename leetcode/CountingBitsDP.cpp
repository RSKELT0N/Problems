class Solution {
    public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        int i = 0; int b = 1;
        
        while(b <= num) {
            while(i < b && i+b <= num){
                dp[i+b] = dp[i] + 1;
                i++;
            }
            i= 0;
            b = b << 1;
        }
        return dp;
    }
};
