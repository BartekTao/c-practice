#include <vector>
using namespace std;
vector<int> constructArr(vector<int>& a) {
    int n = a.size();
    vector<int> dp = vector<int>(n, 1);
    //左下三角形，上至下
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1] * a[i];
    }

    //右上三角形，下至上
    for(int i = n-2; i >= 0; i--){
        dp[i] = dp[i+1] * a[i];
    }
    return dp;
}