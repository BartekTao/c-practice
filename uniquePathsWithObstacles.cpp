#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> dp(n, 0);
    if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
    dp[0] = 1;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(obstacleGrid[i][j] == 1){
                dp[j] = 0;
            }else{
                int left = 0, top = 0;
                top = dp[j];
                if(j!=0){
                    left = dp[j-1];
                }

                if(j > 0 && obstacleGrid[i][j-1] == 1){
                    left = 0;
                }
                if(i > 0 && obstacleGrid[i-1][j] == 1){
                    top = 0;
                }
                dp[j] = left + top;
            }
        }
    }
    return dp[n-1];
}