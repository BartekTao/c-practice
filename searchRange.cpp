#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans = vector<int>{-1,-1};
    if(nums.empty()) return ans;
    
    int n = nums.size();
    int first = 0, end = n-1;
    int mid = 0;
    
    while(first <= end){
        mid = (first+end)/2;

        if(nums[mid] == target && (mid == n-1 || nums[mid] < nums[mid+1])){
            ans[1] = mid;
            break;
        }
        else if(nums[mid] > target){
            end = mid-1;
        }else{
            first = mid + 1;
        }
    }

    first = 0, end = n-1;
    mid = 0;
    while(first <= end){
        mid = (first+end)/2;

        if(nums[mid] == target && (mid == 0 || nums[mid] > nums[mid-1])){
            ans[0] = mid;
            break;
        }
        else if(nums[mid] >= target){
            end = mid-1;
        }else{
            first = mid + 1;
        }
    }


    return ans;
}