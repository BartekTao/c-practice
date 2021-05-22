#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;

    if (nums.empty()) {
		return result;
	}
    
    sort(nums.begin(), nums.end());
    int first = 0;
    int third = nums.size() - 1;
    
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] > 0 )
            return result;
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int second = i + 1;
        int third = nums.size() -1;
        while(third > second){
            int sum = nums[second] + nums[third] + + nums[i];
            if(sum < 0){
                ++second;
            }else if(sum > 0 ){
                --third;
            }else{
                result.push_back({nums[i], nums[second], nums[third]});
                int last_second = nums[second], last_third = nums[third];
                while (second < third && nums[second] == last_second) ++second;
				while (second < third && nums[third] == last_third) --third;
            }
        }
    }
    return result;
}
