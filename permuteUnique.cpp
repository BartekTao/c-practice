#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> permuteUniqueAns;

void rpermuteUnique(vector<int>& nums, int left, int right){
    if(left == right){
        permuteUniqueAns.push_back(nums);
    }else{
        //建hashtable
        unordered_map<int, bool> hashtable;
        for(int target = left; target <= right; target++){
            if(hashtable[nums[target]]){
                continue;
            }else{
                hashtable[nums[target]] = 1;
            }
            swap(nums[left], nums[target]);
            rpermuteUnique(nums, left+1, right);
            swap(nums[target], nums[left]);
        }
    }

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    rpermuteUnique(nums, 0, n-1);
    return permuteUniqueAns;
}
