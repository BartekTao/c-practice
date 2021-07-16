#include <vector>

using namespace std;

int maxValue(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp = vector<int>(n, 0);
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j > 0){
                dp[j] = grid[i][j] + max(dp[j], dp[j-1]);
            }else{
                dp[j] = grid[i][j] + dp[j];
            }
        }
    }
    return dp[n-1];
}