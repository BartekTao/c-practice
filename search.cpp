#include <iostream>
#include <vector>
#include <map>

using namespace std;

int search(vector<int>& nums, int target) {
    int result = -1;

    int l = 0, r = nums.size() - 1, mid;
        
    while(r >= l){
        mid = (l + r)/2;
        if(nums[mid] == target) return mid;

        //左邊有小到大排序
        if(nums[mid] >= nums[l]){
            //target範圍在其中
            if(target >= nums[l] && target < nums[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }else{
            //target範圍在其中
            if(target > nums[mid] && target <= nums[r]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    }

    return result;
}