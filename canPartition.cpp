#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums) {
    int len = nums.size(), sum = 0;
    for(auto i : nums){
        sum+=i;
    }
    if(sum % 2 || len == 1) return false;

    int target = sum/2;
    vector<bool> dp(target+1, 0);
    dp[0] = true;
    for(int i = 0; i < len; i++){
        for(int j = target; j>=nums[i]; j--){
            dp[j] = dp[j] || dp[j-nums[i]];
        }
    }

    return dp[target];
}