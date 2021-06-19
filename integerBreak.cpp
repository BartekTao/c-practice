#include <vector>
#include <iostream>

using namespace std;

int integerBreak(int n) {

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2;i<=n;i++){
        int tmax = 0;
        for(int j=1;j<=i/2;j++){
            tmax = max(tmax, max(j*dp[i-j], j*(i-j)));
        }
        dp[i] = tmax;
    }
    return dp[n];
}