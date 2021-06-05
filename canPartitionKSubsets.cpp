#include <vector>
#include <map>
#include <numeric>

using namespace std;

bool find(vector<int>& nums, int pos, vector<bool>& visited, int sum, int targetNum, int k){
    if(k == 1) return true;
    if(sum == targetNum){
        return find(nums, 0, visited, 0, targetNum, k-1);
    }
    if(sum > targetNum) return false;

    int n_size =  nums.size();
    for(int i = pos; i < n_size; i++ ){
        if(!visited[i]){
            visited[i] = 1;
            if(find(nums, i+1, visited, sum+nums[i], targetNum, k)){
                return true;
            }
            visited[i] = 0;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    //找出平均值
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int targetNum = sum/k;
    if (sum % k) return false;
    vector<bool> visited(nums.size(), 0);
    bool res = find(nums, 0, visited, 0, targetNum, k);
    return res;
}