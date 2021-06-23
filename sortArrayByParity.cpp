#include <vector>
#include <iostream>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int front = 0, end = nums.size()-1;
    while(front < end){
        //奇 + 偶
        if(nums[front] & 1 && !(nums[end] & 1)){
            swap(nums[front], nums[end]);
            end--;
            front++;
        }
        //偶 + 偶
        else if(!(nums[front] & 1) && !(nums[end] & 1)){
            front++;
        }
        //奇 + 奇
        else if(nums[front] & 1 && nums[end] & 1){
            end--;
        }
        //偶 + 奇
        else if(!(nums[front] & 1) && nums[end] & 1){
            front++;
            end--;
        }
    }
    return nums;
}