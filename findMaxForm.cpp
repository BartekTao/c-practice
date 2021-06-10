#include <iostream>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int k = 0; k<len;k++){
        int zeros = 0, ones = 0;
        for (char c : strs[k])
            c == '0' ? zeros++ : ones++;
        for(int i = m; i>= zeros; i--){
            for(int j = n; j >= ones; j-- ){
                dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
            }
        }
    }
    return dp[m][n];
}

