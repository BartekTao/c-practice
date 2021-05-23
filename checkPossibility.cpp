#include <iostream>
#include <vector>

using namespace std;

bool checkPossibility(vector<int>& nums) {
    
    int nums_size = nums.size();
    int count = 0;

    for(int i = 0; i < nums_size-1; i++){
        if(nums[i] <= nums[i+1]){
            continue;
        }else{
            ++count;
            if(count > 1) return false;

            if(i > 0 && nums[i-1] > nums[i+1])
                nums[i+1] = nums[i];
        }
    }
    return true;
}