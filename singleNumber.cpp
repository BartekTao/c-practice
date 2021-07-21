#include <vector>
#include <algorithm>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int sum = 0;
    vector<int> ans = vector<int>{0,0};
    for(int num : nums){
        sum ^= num;
    }
    int mask = 1;
    while(1){
        if((mask & sum) == 0){
            mask = mask << 1;
        }else{
            break;
        }
    }
    for(int num : nums){
        if((num & mask) == 0){
            ans[0] ^=num;
        }else{
            ans[1] ^=num;
        }
    }
    return ans;
}

/*
vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int i = 0;
    while(i < n){
        if(i+1 < n && nums[i] == nums[i+1]){
            i+=2;
        }else{
            ans.push_back(nums[i]);
            i++;
        }
    }
    return ans;
}
*/