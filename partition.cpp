#include <iostream>
#include <vector>
using namespace std;

void dfs(string s, vector<vector<bool>>& dp, vector<vector<string>>& ans, vector<string>& curr, int beginIndex){
    int n = s.length();
    if(beginIndex == n) {
        ans.push_back(curr);
    }
    for(int i = beginIndex; i < n; i++){
        if(dp[beginIndex][i]){
            curr.push_back(s.substr(beginIndex,i-beginIndex+1));
            dfs(s, dp, ans, curr, i+1);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
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
    vector<vector<string>> ans;
    vector<string> curr;
    dfs(s, dp, ans, curr, 0);
    return ans;
}

