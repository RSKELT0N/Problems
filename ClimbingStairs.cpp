#include <iostream>

using namespace std;

int climbStairs(long long n) {

    long dp[n];
    for (int i = 0; i < n; i++) {
        if(i < 3)
            dp[i] = i+1;
        else
            dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

int main() {
    cout << climbStairs(12);
    return 0;
}
