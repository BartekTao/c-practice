#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int numsSize = nums.size();
    sort(nums.begin(), nums.end());

    int closestSum = nums[0] + nums[1] + nums[2];
    for(int i = 0; i < numsSize; i++){
        int second = i+1;
        int third = numsSize - 1;
        while(second < third){
            int sum = nums[i] + nums[second] + nums[third];

            if(!(abs(closestSum - target) < abs(sum - target))) {
                closestSum = sum;
            }

            if(sum < target){
                ++second;
            }else if(sum > target){
                --third;
            }else{
                return sum;
            }
        }
    }
    return closestSum;
}