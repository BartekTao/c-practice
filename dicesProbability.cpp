#include <vector>

using namespace std;

vector<double> dicesProbability(int n) {
    vector<double> dp = vector<double>(6, 1.0/6.0);
    
    //i = 骰子數量
    for(int i = 2; i<=n;i++){
        //骰子為i顆時，可能的骰子和的總數
        vector<double> dpTemp = vector<double>(5*i + 1, 0);
        //dp = 骰子為i-1的機率
        for(int j = 0; j < dp.size(); j++){
            for(int k = 0; k < 6; k++){
                dpTemp[j+k] += dp[j] / 6.0;
            }
        }
        dp = dpTemp;
    }
    return dp;
}