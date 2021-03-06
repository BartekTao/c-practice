#include <vector>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n, 0);
    dp[0] = grid[0][0];

    for(int i = 0;i<m;i++){
        for(int j = 0; j<n ; j++){
            if(j>0 && i>0){
                dp[j] = min(dp[j], dp[j-1])+grid[i][j];
            }else if(i>0){
                dp[j] = dp[j]+grid[i][j];
            }else if(j>0){
                dp[j] = dp[j-1]+grid[i][j];
            }
        }
    }
    return dp[n-1];
}