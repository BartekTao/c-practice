#include <vector>

using namespace std;

//減少空間
int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    int lastDp = nums[0];
    int ans = nums[0];
    for(int i = 1; i < len; i++){
        lastDp = max(nums[i], lastDp + nums[i]);
        ans = max(lastDp, ans);
    }
    return ans;
}
/*
int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp = vector<int>(len, 0);
    dp[0] = nums[0];
    int ans = dp[0];
    for(int i = 1; i < len; i++){
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        ans = max(dp[i], ans);
    }
    return ans;
}
*/