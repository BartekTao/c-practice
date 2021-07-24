#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxV = 14, minV = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == 0) continue;
        if(i != 0 && nums[i] == nums[i-1]) return false;
        maxV = max(maxV, nums[i]);
        minV = min(minV, nums[i]);
    }
    if(maxV-minV <= 4) return true;
    else return false;
}