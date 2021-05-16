#include <iostream>
#include <vector>
#include <map>

using namespace std;

int findRepeatNumber(vector<int>& nums) {
        map<int, bool> checkRepeat;
        for(int i = 0; i < nums.size(); i++){
            if(checkRepeat[nums[i]])
                return nums[i];
            else{
                checkRepeat[nums[i]] = true;
            }
        }
        return -1;
    }