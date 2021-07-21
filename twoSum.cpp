#include <vector>
#include <algorithm>

using namespace std;

vector<int> getTowSum(vector<int>& nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int first = 0;
    int end = n-1;
    while(first < end){
        int ans = nums[first] + nums[end];
        if(ans == target){
            return { nums[first], nums[end] };
        }
        else if(ans > target){
            end--;
        }else{
            first++;
        }
    }
    return{};
}
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> a = vector<int>(n);
    for(int i=0;i<nums.size();i++){
        a[i]=nums[i];
    }
    vector<int> temp = getTowSum(a, target);
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(nums[i] == temp[0] || nums[i] == temp[1]){
            ans.push_back(i);
        }
    }
    return ans;
}