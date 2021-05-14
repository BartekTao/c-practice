#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
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

    int maxArea(vector<int>& height) {
        for(int i = 1; i < height.size(); i++){
            
        }
        return -1;
    }
};

int main(){
    vector<int> nums { 1, 2, 3, 1 };

    Solution s;

    int result = s.findRepeatNumber(nums);
    cout << result;
    cout << endl;
}



