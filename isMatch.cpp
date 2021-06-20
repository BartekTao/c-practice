#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));
    dp[0][0] = true;
    for(int j = 2; j <= n; j++){
        if(p[j-1] == '*' && dp[0][j-2]){
            dp[0][j] = true;
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '.'){
                dp[i][j] = dp[i-1][j-1];
            }else if(j > 1 && p[j-1] == '*'){
                if(s[i-1] != p[j-2] && p[j-2] != '.'){
                    dp[i][j] = dp[i][j-2];
                }else{
                    //三種狀況皆可符合
                    //複製前項0次 => 看p前兩項
                    //複製前項1次 => 看p前一項
                    //複製前項n次 => 看s前一項
                    dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                }
            }
        }
    }
    return dp[m][n];
}