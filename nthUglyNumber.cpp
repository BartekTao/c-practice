#include <vector>

using namespace std;

int nthUglyNumber(int n) {
    //dp
    //dp[i] = num
    //i = 第i個醜數
    //num = 醜數出現的數字
    //由第一個醜數開始往後推
    //後面的醜數皆為前面醜數乘與2或3或5得來
    //故可以設定三個矛點(T2,T3,T5)位於第一個醜數，分別乘與2或3或5，並取得三個乘積的最小值來取得下一個醜數為多少
    //min(1*2,1*3,1*5) = 1*2 => 下一個醜數為2 => 並將T2往後移動一個index

    vector<int> dp = vector<int>(n+1);
    dp[1] = 1;
    int t2 = 1,t3 = 1,t5 = 1;
    for(int i = 2; i <= n; i++){
        int t2n = dp[t2]*2;
        int t3n = dp[t3]*3;
        int t5n = dp[t5]*5;
        dp[i] = min(t2n, min(t3n, t5n));
        if(dp[i] == t2n) t2++;
        if(dp[i] == t3n) t3++;
        if(dp[i] == t5n) t5++;
    }
    return dp[n];
}