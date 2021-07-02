#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> result;

void permutation(vector<int> &nums,int left,int right){
    if(left == right){
        result.push_back(nums);
    }else{
        for(int t = left; t <= right; t++){
            swap(nums[left], nums[t]);
            permutation(nums, left+1, right);
            swap(nums[t], nums[left]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    permutation(nums, 0, n-1);
    return result;
}

