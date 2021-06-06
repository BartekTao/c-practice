#include <iostream>
#include <vector>
using namespace std;

int minCut(string s) {
    int len = s.size();
    vector<vector<bool>> dp (len, vector<bool>(len, false));
    for(int j=0;j<len;j++){
        for(int i=j;i>=0;i--){
            if(i == j){
                dp[i][j] = true;
            }
            else if(j - i <= 2){
                dp[i][j] = s[i] == s[j];
            }else{
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }
    }

    vector<int> f(len);
    for(int j = 1; j<len; j++){
        if(dp[0][j]) f[j] = 0;
        else{
            f[j] = f[j-1] + 1;
            for(int i = 1; i<=j;i++){
                if(dp[i][j]){
                    f[j] = min(f[i-1] + 1, f[j]);
                }
            }
        }
    }
    return f[len-1];
}